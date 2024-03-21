"""This is the Azure onboarding script for Rapid7's InsightCloudSec (ICS)."""

import json
import logging
import os
import re
from json import JSONDecodeError, dumps, loads
from subprocess import (
    PIPE,
    CalledProcessError,
    CompletedProcess,
    run,
)
from typing import (
    Any,
    Dict,
    List,
    Optional,
    Set,
    Tuple,
    cast,
)

import requests


# Declare the choice of organization harvesting or not (this can be backfilled externally).
CHOSEN_ORGANIZATION_HARVESTING: Optional[bool] = False

# Declare the choice of partition (this can be backfilled externally).
# Tolerated values include: AZURE_ARM, AZURE_GOV
CHOSEN_PARTITION: str = "AZURE_ARM"

# Declare the choice of using a certificate or not (this can be backfilled externally).
CHOSEN_USE_CERTIFICATE: Optional[bool] = False


# Microsoft Graph Application ID
MICROSOFT_GRAPH_APPLICATION_ID: str = "00000003-0000-0000-c000-000000000000"
# Create the set of Microsoft Graph Application API permissions.
MICROSOFT_GRAPH_API_PERMISSIONS: List[str] = [
    "AuditLog.Read.All",  # Needed to see if MFA is enabled.
    "Directory.Read.All",
]

# Let's create the organization reader's role name.
ORGANIZATION_READER_ROLE_NAME: str = "InsightCloudSec Organization Reader User Role (Tenant)"
# Let's create the organization reader's role dsecription.
ORGANIZATION_READER_ROLE_DESCRIPTION: str = "Provides access to read the organization structure for a given Tenant."
# Let's create the organization reader action permissions.
ORGANIZATION_READER_ACTIONS: List[str] = [
    "Microsoft.Management/managementGroups/descendants/read",
    "Microsoft.Management/managementGroups/read",
    "Microsoft.Management/managementGroups/settings/read",
    "Microsoft.Resources/subscriptions/read",
]
# Let's create the organization reader not action permissions.
ORGANIZATION_READER_NOT_ACTIONS: List[str] = []
# Let's create the organization reader data action permissions.
ORGANIZATION_READER_DATA_ACTIONS: List[str] = []
# Let's create the organization reader not data action permissions.
ORGANIZATION_READER_NOT_DATA_ACTIONS: List[str] = []

# Declare the Azure Active Directory's "create service principal" command.
CREATE_SERVICE_PRINCIPAL_COMMAND: List[str] = [
    "az",
    "ad",
    "sp",
    "create-for-rbac",
    "-o",
    "json",
]


# Declare the Azure Active Directory's "list service principal" command.
LIST_SERVICE_PRINCIPAL_COMMAND: List[str] = [
    "az",
    "ad",
    "sp",
    "list",
    "-o",
    "json",
]


# Declare the Azure CLI account list command.
ACCOUNT_LIST_COMMAND: List[str] = [
    "az",
    "account",
    "list",
]


# Let's ask for the chosen name of the ICS application registration.
DEFAULT_APPLICATION_REGISTRATION_NAME: str = "Rapid7 InsightCloudSec Harvester"
# Pattern that matches a non-dashed GUID.
NO_DASH_PATTERN = re.compile(r"^[^\W_]{32}$")
# Pattern that matches a dashed GUID.
DASH_PATTERN = re.compile(r"^[^\W_]{8}-[^\W_]{4}-[^\W_]{4}-[^\W_]{4}-[^\W_]{12}$")

# Declare the ICS role URL.
ICS_ROLE_URL: str = "http://get.divvycloud.com/policies"

# Declare the default partition role filenames.
DEFAULT_ROLE_FILENAMES: List[str] = [
    "Azure-Custom-Reader-User-Role.json",
    "Azure-Reader-Plus-User-Role.json",
    "Azure-Power-User-Role.json",
]

# Declare the government partition role filenames.
GOVERNMENT_ROLE_FILENAMES: List[str] = [
    "Azure-GovCloud-Custom-Reader-User-Role.json",
    "Azure-GovCloud-Power-User-Role.json",
]

# Declare the Azure Active Directory's "create role definition" command.
CREATE_ROLE_DEFINITION_COMMAND: List[str] = [
    "az",
    "role",
    "definition",
    "create",
]


# Declare the Azure Active Directory's "list role definition" command.
LIST_ROLE_DEFINITION_COMMAND: List[str] = [
    "az",
    "role",
    "definition",
    "list",
    "--custom-role-only",
    "true",
]

# Declare the Azure Active Directory's "update role definition" command.
UPDATE_ROLE_DEFINITION_COMMAND: List[str] = [
    "az",
    "role",
    "definition",
    "update",
]


# Declare the Azure Active Directory's "create role assignment" command.
CREATE_ROLE_ASSIGNMENT_COMMAND: List[str] = [
    "az",
    "role",
    "assignment",
    "create",
]


# Declare the Azure Active Directory's "list role assignment" command.
LIST_ROLE_ASSIGNMENT_COMMAND: List[str] = [
    "az",
    "role",
    "assignment",
    "list",
    "--all",
]


# Declare the Azure Active Directory's "add API permission" command.
ADD_API_PERMISSION_COMMAND: List[str] = [
    "az",
    "ad",
    "app",
    "permission",
    "add",
]

# Declare the Azure Active Directory's "list API permissions" command.
LIST_API_PERMISSIONS_COMMAND: List[str] = [
    "az",
    "ad",
    "app",
    "permission",
    "list",
]

# Declare the Azure Active Directory's "show service principal" command.
SHOW_SERVICE_PRINCIPAL: List[str] = [
    "az",
    "ad",
    "sp",
    "show",
    "-o",
    "json",
]

# Declare the Azure "REST POST" command.
REST_POST_COMMAND: List[str] = [
    "az",
    "rest",
    "--method",
    "POST",
]


class CustomFormatter(logging.Formatter):
    """Create a custom streaming formatter (with colors)."""

    grey = "\x1b[38;20m"
    yellow = "\x1b[33;20m"
    red = "\x1b[31;20m"
    bold_red = "\x1b[31;1m"
    reset = "\x1b[0m"
    format_descriptor: str = "%(asctime)s- %(levelname)s - %(message)s"

    FORMATS: dict = {
        logging.DEBUG: grey + format_descriptor + reset,
        logging.INFO: grey + format_descriptor + reset,
        logging.WARNING: yellow + format_descriptor + reset,
        logging.ERROR: red + format_descriptor + reset,
        logging.CRITICAL: bold_red + format_descriptor + reset,
    }

    def format(self, record: logging.LogRecord) -> str:
        log_fmt = self.FORMATS.get(record.levelno)
        formatter = logging.Formatter(log_fmt)
        return formatter.format(record)


def create_logger(name: str, logger_level: int = logging.INFO, console_level: int = logging.INFO) -> logging.Logger:
    """Create a named logger."""

    # Declare the local module's logger.
    logger: logging.Logger = logging.getLogger(name)
    # Set the level of the handler.
    logger.setLevel(logger_level)

    # create console handler with a higher log level
    console_handler = logging.StreamHandler()
    # Set the level of the handler.
    console_handler.setLevel(console_level)
    # create formatter and add it to the handlers
    console_handler.setFormatter(CustomFormatter())
    # Add the handler to the logger
    logger.addHandler(console_handler)

    return logger


# Create the logger.
LOGGER: logging.Logger = create_logger(__name__)


def run_shell_script(
    *,
    command: List[str],
    parameters: Optional[List[str]] = None,
    log_error: bool = True,
    log_output: bool = False,
) -> Optional[str]:
    """Run a shell script (and handle errors)."""

    # Copy the incoming command (so it doesn't get corrupted).
    command = command.copy()

    # If there are parameters...
    if parameters:
        # Append the parameters.
        command += parameters

    try:
        # Run the shell command.
        LOGGER.debug("About to execute the shell command: %s", " ".join(command))
        completed_process: CompletedProcess = run(
            command,
            stdout=PIPE,
            stderr=PIPE,
            text=True,
            check=True,
        )
        # Check the return code.
        LOGGER.debug(
            "Command execution completed with return code: %i",
            completed_process.returncode,
        )

        # Log the response.
        LOGGER.debug("The response was: %s", completed_process.stdout)

        return completed_process.stdout

    except CalledProcessError as exception:
        if log_error:
            # Log the exception.
            LOGGER.error(exception.stderr)
            LOGGER.error(exception, exc_info=True)
        if log_output:
            # Log the output.
            LOGGER.error(exception.output, exc_info=True)

    except FileNotFoundError as exception:
        if log_error:
            # Log the exception.
            LOGGER.error(exception, exc_info=True)

    return None


def run_shell_script_with_json_response(
    *,
    command: List[str],
    parameters: Optional[List[str]] = None,
    log_error: bool = True,
    log_output: bool = False,
) -> Optional[Any]:
    """Run a shell script and process resultant JSON (and handle errors)."""

    # Run the shell script.
    stdout: Optional[str] = run_shell_script(
        command=command,
        parameters=parameters,
        log_error=log_error,
        log_output=log_output,
    )
    # Was there output returned...?
    if stdout:
        try:
            # Attempt to convert to JSON.
            output: Any = loads(stdout)
            LOGGER.debug("The JSON response was: %s", dumps(output, indent=2))
            return output

        except JSONDecodeError as exception:
            # Log the exception.
            LOGGER.error(exception, exc_info=True)

    return None


def id_option(id_value: str) -> List[str]:
    """Create the CLI option for the ID."""
    return ["--id", id_value]


def query_option(key_value: str) -> List[str]:
    """Create the CLI option for the query value."""
    return ["--query", key_value]


def filter_option(key_value: str) -> List[str]:
    """Create the CLI option for the filter value."""
    return ["--filter", key_value]


def api_id_option(id_value: str) -> List[str]:
    """Create the CLI option for the API ID."""
    return ["--api", id_value]


def api_permission_id_option(id_value: str) -> List[str]:
    """Create the CLI option for the API permission ID."""
    return ["--api-permissions", id_value + "=Role"]


def role_option(role_id: str) -> List[str]:
    """Create the CLI option for the role."""
    return ["--role", role_id]


def assignee_option(assignee_id: str) -> List[str]:
    """Create the CLI option for the assignee."""
    return ["--assignee", assignee_id]


def scope_option(scope: str) -> List[str]:
    """Create the CLI option for the scope."""
    return ["--scope", scope]


def username_option(username: str) -> List[str]:
    """Create the CLI option for the username."""
    return ["--username", username]


def display_name_option(display_name: str) -> List[str]:
    """Create the CLI option for the display name."""
    return ["--display-name", display_name]


def password_option(password: str) -> List[str]:
    """Create the CLI option for the password."""
    return ["--password", password]


def tenant_option(tenant_id: str) -> List[str]:
    """Create the CLI option for the tenant."""
    return ["--tenant", tenant_id]


def role_name_option(role_name: str) -> List[str]:
    """Create the CLI option for the role name."""
    return ["--name", role_name]


def uri_option(uri: str) -> List[str]:
    """Create the CLI option for the URI value."""
    return ["--uri", uri]


def body_option(body: str) -> List[str]:
    """Create the CLI option for the URI value."""
    return ["--body", body]


def role_definition_option(role_definition: str) -> List[str]:
    """Create the CLI option for the role definition."""
    return ["--role-definition", role_definition]


def certificate_option() -> List[str]:
    """Create the CLI option for the certificate."""
    return ["--create-cert"]


def create_service_principal(display_name: str, use_certificate: bool) -> dict:
    """Create the Azure role assignment by ID."""

    # Initialize the command.
    command: List[str] = CREATE_SERVICE_PRINCIPAL_COMMAND.copy()
    # Update the command with the provided input variables.
    command.extend(display_name_option(display_name=display_name))
    # If we want to use a certificate...
    if use_certificate:
        # Update the command with the provided input variables.
        command.extend(certificate_option())
    # Run the shell script.
    LOGGER.info("Creating service principal/application registration via: %s", command)
    return cast(dict, run_shell_script_with_json_response(command=command, log_error=True))


def list_service_principals(display_name: str) -> List[dict]:
    """Create the Azure role assignment by ID."""

    # Initialize the command.
    command: List[str] = LIST_SERVICE_PRINCIPAL_COMMAND.copy()
    # Update the command with the provided input variables.
    command.extend(filter_option(f"displayname eq '{display_name}' and servicePrincipalType eq 'Application'"))
    # Run the shell script.
    LOGGER.debug("Listing service principal/application registration via: %s", command)
    return cast(List[dict], run_shell_script_with_json_response(command=command, log_error=True))


def get_subscriptions() -> List[dict]:
    """Find the Azure subscriptions."""

    # Initialize the command.
    command: List[str] = ACCOUNT_LIST_COMMAND.copy()
    # Run the shell script.
    return cast(List[dict], run_shell_script_with_json_response(command=command))


def get_bool(inputs: dict, key_name: str, default_value: bool) -> bool:
    """Get a bool from a dict, where None or wrong types revert to the default."""

    # Grab value associated with the key.
    input_value: Optional[Any] = inputs.get(key_name, default_value)
    # Be sure that the value is the expected type.
    if not isinstance(input_value, bool):
        # Wrong type, so return default.
        return default_value
    # Return the input value.
    return input_value


def find_target_subscription(
    targeted_tenant_id: str,
) -> Tuple[Optional[str], List[str]]:
    """Find the target subscription (and adjacent subscriptions)."""

    LOGGER.info("Examining subscriptions in tenant [%s]...", targeted_tenant_id)

    # Grab the current set of subscriptions.
    subscriptions: Optional[Any] = get_subscriptions()
    subscription_ids: List[str] = []

    # Declare the default subscription and tenant IDs.
    default_subscription_id: Optional[str] = None

    # Check to be sure that the subscriptions are the expected type.
    if isinstance(subscriptions, list):
        # Iterate over the existing subscriptions...
        for subscription in subscriptions:
            # Grab the tenant ID.
            tenant_id: str = subscription["tenantId"]
            # If the tenant ID does not match...
            if tenant_id != targeted_tenant_id:
                # Keep going!
                continue
            # Grab the subscription name.
            subscription_name: str = subscription["name"]
            # Grab the subscription ID.
            subscription_id: str = subscription["id"]
            # Check to see if this is the default subscription.
            is_default: bool = get_bool(subscription, "isDefault", False)
            # Store the ID in the list.
            subscription_ids.append(subscription_id)
            # If this is the default subscription...
            if is_default:
                # Store them for the case when no input was provided.
                default_subscription_id = subscription_id
                LOGGER.info(
                    'Default subscription: "%s" [%s]',
                    subscription_name,
                    subscription_id,
                )
            else:
                LOGGER.info(
                    'Subscription: "%s" [%s]',
                    subscription_name,
                    subscription_id,
                )

    # Return
    return (default_subscription_id, subscription_ids)


def create_role_definition(role_definition: str) -> dict:
    """Create the Azure role by definition."""

    # Initialize the command.
    command: List[str] = CREATE_ROLE_DEFINITION_COMMAND.copy()
    LOGGER.info("Creating role definition via: %s", command)
    # Update the command with the provided input variables.
    command.extend(role_definition_option(role_definition=role_definition))
    # Run the shell script.
    return cast(dict, run_shell_script_with_json_response(command=command, log_error=True))


def list_role_definitions(role_name: str, scope: str) -> List[dict]:
    """List the Azure roles by name."""

    # Initialize the command.
    command: List[str] = LIST_ROLE_DEFINITION_COMMAND.copy()
    # Update the command with the provided input variables.
    command.extend(role_name_option(role_name=role_name))
    command.extend(scope_option(scope=scope))
    # Run the shell script.
    LOGGER.debug("Listing role definitions via: %s", command)
    return cast(List[dict], run_shell_script_with_json_response(command=command, log_error=True))


def update_role_definition(role_definition: str) -> None:
    """Udpate the Azure role by definition."""

    # Initialize the command.
    command: List[str] = UPDATE_ROLE_DEFINITION_COMMAND.copy()
    LOGGER.info("Updating the role definition via: %s", command)
    # Update the command with the provided input variables.
    command.extend(role_definition_option(role_definition=role_definition))
    # Run the shell script.
    run_shell_script_with_json_response(command=command, log_error=True)


def create_role_assignment(role_id: str, assignee_id: str, scope: str) -> None:
    """Create the Azure role assignment by role ID, assignee ID, and scope."""

    # Initialize the command.
    command: List[str] = CREATE_ROLE_ASSIGNMENT_COMMAND.copy()
    # Update the command with the provided input variables.
    command.extend(role_option(role_id=role_id))
    command.extend(assignee_option(assignee_id=assignee_id))
    command.extend(scope_option(scope=scope))

    # Run the shell script.
    LOGGER.info("Creating role assignment via: %s", command)
    run_shell_script_with_json_response(command=command, log_error=True)


def list_role_assignments(role_id: str, assignee_id: str) -> List[dict]:
    """List the Azure role assignments by role ID, assignee ID, and scope."""

    # Initialize the command.
    command: List[str] = LIST_ROLE_ASSIGNMENT_COMMAND.copy()
    # Update the command with the provided input variables.
    command.extend(role_option(role_id=role_id))
    command.extend(assignee_option(assignee_id=assignee_id))

    # Run the shell script.
    LOGGER.debug("Listing role assignments via: %s", command)
    return cast(List[dict], run_shell_script_with_json_response(command=command, log_error=True))


def add_api_permission(id_value: str, api_id: str, api_permission_id: str) -> None:
    """Add the API permission to object associated with the application registration ID, API ID, and API permission ID."""

    # Initialize the command.
    command: List[str] = ADD_API_PERMISSION_COMMAND.copy()
    # Update the command with the provided input variables.
    command.extend(id_option(id_value=id_value))
    command.extend(api_id_option(id_value=api_id))
    command.extend(api_permission_id_option(id_value=api_permission_id))
    # Run the shell script.
    LOGGER.info("Adding API permission via: %s", command)
    run_shell_script_with_json_response(command=command, log_error=True)


def list_api_permissions(id_value: str) -> List[dict]:
    """List the API permissions for an object associated with the application registration ID."""

    # Initialize the command.
    command: List[str] = LIST_API_PERMISSIONS_COMMAND.copy()
    # Update the command with the provided input variables.
    command.extend(id_option(id_value=id_value))
    # Run the shell script.
    LOGGER.debug("Listing API permissions via: %s", command)
    return cast(List[dict], run_shell_script_with_json_response(command=command, log_error=True))


def get_object_id(id_value: str) -> str:
    """Given the object ID associated with a service principal."""

    # Initialize the command.
    command: List[str] = SHOW_SERVICE_PRINCIPAL.copy()
    # Update the command with the provided input variables.
    command.extend(id_option(id_value=id_value))
    command.extend(query_option(key_value="id"))
    # Run the shell script.
    LOGGER.debug("Getting object ID via: %s", command)
    return cast(str, run_shell_script_with_json_response(command=command, log_error=True))


def get_app_roles(id_value: str, app_role: str) -> List[dict]:
    """Given the app role(s) associated with a service principal."""

    # Initialize the command.
    command: List[str] = SHOW_SERVICE_PRINCIPAL.copy()
    # Update the command with the provided input variables.
    command.extend(id_option(id_value=id_value))
    command.extend(query_option(key_value=f"appRoles[?value=='{app_role}']"))
    # Run the shell script.
    LOGGER.debug("Listing Application Roles via: %s", command)
    return cast(List[dict], run_shell_script_with_json_response(command=command, log_error=True))


def make_rest_post(uri: str, body: str) -> None:
    """Make a REST POST via the Azure CLI."""

    # Initialize the command.
    command: List[str] = REST_POST_COMMAND.copy()
    # Update the command with the provided input variables.
    command.extend(uri_option(uri=uri))
    command.extend(body_option(body=body))
    # Run the shell script.
    LOGGER.info("Updating REST via: %s", command)
    run_shell_script_with_json_response(command=command, log_error=True)


def grant_admin_consent(application_id: str, permission: str) -> None:
    """Grant the admin consent to object associated with the application registration ID."""

    # Context for this command: https://github.com/Azure/azure-cli/issues/12137#issuecomment-596567479

    # Get the object ID that acts as the principal ID (for the assignment) associated with the service principal.
    principal_id: str = get_object_id(id_value=application_id)
    # Grab the object ID that acts as the resource ID (for the assignment) associated with the Microsoft Graph API.
    resource_id: str = get_object_id(id_value=MICROSOFT_GRAPH_APPLICATION_ID)

    # Create the body.
    body: dict = {
        "principalId": principal_id,
        "resourceId": resource_id,
        "appRoleId": permission,
    }
    # Create the URI.
    uri: str = f"https://graph.microsoft.com/v1.0/servicePrincipals/{principal_id}/appRoleAssignments"
    # Make the REST POST to grant the admin consent.
    make_rest_post(uri=uri, body=json.dumps(body))


def create_management_group_scope_from_management_group_id(management_group_id: str) -> str:
    """Create the management group scope from the management group ID."""

    return f"/providers/Microsoft.Management/managementGroups/{management_group_id}"


def create_subscription_scope_from_subscription_id(subscription_id: str) -> str:
    """Create the subscription scope from the subscription ID."""

    return f"/subscriptions/{subscription_id}"


def configure_api_permissions(application_id: str) -> None:
    """Configure the API permissions for the application registration ID."""

    # Look up the existing API permissions.
    api_permissions: List[dict] = list_api_permissions(
        id_value=application_id,
    )

    # Create the list of Microsoft Graph API permissions needed.
    graph_api_permissions_needed: dict = {}

    # For each of the application roles...
    for api_permission_name in MICROSOFT_GRAPH_API_PERMISSIONS:
        # Get the application role ID for AuditLog.Read.All.
        api_permission_id: str = get_app_roles(id_value=MICROSOFT_GRAPH_APPLICATION_ID, app_role=api_permission_name)[
            0
        ]["id"]
        # Start with the assumption that we need this permission.
        graph_api_permissions_needed[api_permission_id] = True

    # If the graph API permission is found...
    graph_api_permission: Optional[dict] = next(
        (
            api_permission
            for api_permission in api_permissions
            if api_permission["resourceAppId"] == MICROSOFT_GRAPH_APPLICATION_ID
        ),
        None,
    )

    # If there are existing Microsoft Graph API API permissions...
    if graph_api_permission:
        # Look at the existing role accesses...
        role_accesses = graph_api_permission["resourceAccess"]
        # For each permission needed...
        for permission in graph_api_permissions_needed:
            # For each existing role access...
            for role_access in role_accesses:
                # If the role access exists...
                if role_access["id"] == permission and role_access["type"] == "Role":
                    # Indicate the the permission is not needed.
                    graph_api_permissions_needed[permission] = False

    # For each Microsoft Graph API permission needed...
    for permission, needed in graph_api_permissions_needed.items():
        # If the permission is not needed...
        if not needed:
            continue
        # Add a new Microsoft Graph API permission.
        LOGGER.info('Adding "%s" API permission for "%s"', "Microsoft Graph", permission)
        add_api_permission(
            id_value=application_id,
            api_id=MICROSOFT_GRAPH_APPLICATION_ID,
            api_permission_id=permission,
        )

        # Grant admin consent.
        grant_admin_consent(application_id=application_id, permission=permission)


def get_subscription_id(tenant_id: str) -> Tuple[str, List[str]]:
    """Get the subscription ID (and adjacent subscriptions) from the tenant ID and/or inputs."""

    # Grab the default subscription ID (and alternatives).
    (default_subscription_id, subscription_ids) = find_target_subscription(targeted_tenant_id=tenant_id)

    # Request the subscription ID of interest.
    print()  # noqa: T201
    subscription_id: Optional[str] = (
        input(f"Enter the subscription ID of primary interest [{default_subscription_id}]: ") or default_subscription_id
    )
    print()  # noqa: T201

    # If there is no subscription ID...
    if not subscription_id:
        raise ValueError("Unable to determine subscription ID!")

    # If the subscription ID doesn't match the expected format..
    if not (re.match(NO_DASH_PATTERN, subscription_id) or re.match(DASH_PATTERN, subscription_id)):
        raise ValueError(f"Invalid or malformed subscription ID: {subscription_id}")

    # If the GUID is a dashless pattern...
    if re.match(NO_DASH_PATTERN, subscription_id):
        # Format the GUID.
        subscription_id = "-".join(
            [
                subscription_id[:8],
                subscription_id[8:12],
                subscription_id[12:16],
                subscription_id[16:20],
                subscription_id[20:32],
            ]
        )

    # Check to see if the subscription is recognized or not...
    if subscription_id not in subscription_ids:
        raise ValueError(f"Subscription ID [{subscription_id}] not associated with tenant [{tenant_id}].")

    return (subscription_id, subscription_ids)


def make_comparable(incoming: List[str]) -> Set[str]:
    """Convert a list to be suitable for comparison."""
    return set([designator.lower() for designator in incoming])


def role_definition_changed(incoming_role: dict, found_role: dict) -> Tuple[bool, bool]:
    """Check to see if the role definition has changed."""

    # Grab the pieces of the incoming role.
    incoming_description: str = incoming_role["Description"]
    incoming_actions: Set[str] = make_comparable(incoming_role["Actions"])
    incoming_not_actions: Set[str] = make_comparable(incoming_role["NotActions"])
    incoming_data_actions: Set[str] = make_comparable(incoming_role["DataActions"])
    incoming_not_data_actions: Set[str] = make_comparable(incoming_role["NotDataActions"])
    incoming_scopes: Set[str] = make_comparable(incoming_role["AssignableScopes"])

    # Grab the pieces of the found role.
    found_description: str = found_role["description"]
    found_actions: Set[str] = make_comparable(found_role["permissions"][0]["actions"])
    found_not_actions: Set[str] = make_comparable(found_role["permissions"][0]["dataActions"])
    found_data_actions: Set[str] = make_comparable(found_role["permissions"][0]["notActions"])
    found_not_data_actions: Set[str] = make_comparable(found_role["permissions"][0]["notDataActions"])
    found_scopes: Set[str] = make_comparable(found_role["assignableScopes"])

    # If there are any pieces of the role that have changed...
    role_changed: bool = (
        incoming_description != found_description
        or incoming_actions != found_actions
        or incoming_not_actions != found_not_actions
        or incoming_data_actions != found_data_actions
        or incoming_not_data_actions != found_not_data_actions
    )

    # Let's report the description change.
    if found_description != incoming_description:
        LOGGER.info("Description will be updated")

    # Let's report the additions.
    if incoming_actions - found_actions:
        LOGGER.info("Role will be updated to add the following actions: %s", incoming_actions - found_actions)
    if incoming_not_actions - found_not_actions:
        LOGGER.info(
            "Role will be updated to add the following not actions: %s", incoming_not_actions - found_not_actions
        )
    if incoming_data_actions - found_data_actions:
        LOGGER.info(
            "Role will be updated to add the following data actions: %s", incoming_data_actions - found_data_actions
        )
    if incoming_not_data_actions - found_not_data_actions:
        LOGGER.info(
            "Role will be updated to add the following not data actions: %s",
            incoming_not_data_actions - found_not_data_actions,
        )

    # Let's report the subtractions.
    if found_actions - incoming_actions:
        LOGGER.info("Role will be updated to remove the following actions: %s", found_actions - incoming_actions)
    if found_not_actions - incoming_not_actions:
        LOGGER.info(
            "Role will be updated to remove the following not actions: %s", found_not_actions - incoming_not_actions
        )
    if found_data_actions - incoming_data_actions:
        LOGGER.info(
            "Role will be updated to remove the following data actions: %s", found_data_actions - incoming_data_actions
        )
    if found_not_data_actions - incoming_not_data_actions:
        LOGGER.info(
            "Role will be updated to remove the following not data actions: %s",
            found_not_data_actions - incoming_not_data_actions,
        )

    # If the scope has grown...
    scope_changed: bool = len(incoming_scopes - found_scopes) != 0

    # Let's report the scope expansion.
    if incoming_scopes - found_scopes:
        LOGGER.info("Scope will be expanded: %s", incoming_scopes - found_scopes)
    # Let's report the scope contraction (this should pretty much never happen).
    if found_scopes - incoming_scopes:
        LOGGER.info("Scope will be contracted: %s", found_scopes - incoming_scopes)

    return (role_changed, scope_changed)


def create_or_maybe_update_role(incoming_role: dict, subscription_ids: Optional[List[str]] = None) -> dict:
    """Let's create or maybe update a custom role."""

    # Grab the role name.
    role_name: str = incoming_role["Name"]

    # Grab the scope.
    scope: str = incoming_role["AssignableScopes"][0]

    # Declare the organization reader role definition.
    role_definition: dict

    # Declare the found roles (may end up empty)
    role_definitions: List[dict]

    # Declare the adjacent scope.
    adjacent_scope: Optional[str] = None

    # Look in the current scope...
    role_definitions = list_role_definitions(role_name=role_name, scope=scope)

    # Have we found the role definition in the current scope? If not, look in adjacent scopes (when provided)...
    if not role_definitions and subscription_ids:
        # Look in the adjacent scopes.
        for subscription_id in subscription_ids:
            # Create the adjacent scope.
            adjacent_scope = create_subscription_scope_from_subscription_id(subscription_id=subscription_id)
            # If the adjacent scope has already been considered...
            if adjacent_scope == scope:
                # Keep going!
                continue
            # Look in the adjacent scope...
            role_definitions = list_role_definitions(role_name=role_name, scope=adjacent_scope)
            # The role definition was found!
            if role_definitions:
                break

    # We have some sort of match...
    if role_definitions:
        LOGGER.info('Found existing custom role with name "%s" within scope "%s"', role_name, adjacent_scope or scope)
        # Grab the role definition.
        role_definition = role_definitions[0]

        # Look at the found scopes (convert to lowercase for consistency).
        found_scopes: Set[str] = set(scope.lower() for scope in role_definition["assignableScopes"])
        # Look at the incoming scopes (convert to lowercase for consistency).
        incoming_scopes: Set[str] = set(scope.lower() for scope in incoming_role["AssignableScopes"])
        # Create the list of all scopes (use union of sets to de-deduplicate).
        all_scopes: List[str] = list(incoming_scopes | found_scopes)

        # Update the assignable scopes.
        incoming_role["AssignableScopes"] = all_scopes

        # Check to see if role has changed.
        (role_changed, scope_changed) = role_definition_changed(incoming_role=incoming_role, found_role=role_definition)

        # If the role has not changed...
        if not role_changed and not scope_changed:
            LOGGER.info("Role matches (and within scope)!")

        elif not role_changed and scope_changed:
            LOGGER.info('Broadening scope of custom role with name "%s"', role_name)
            # Update the role definition.
            update_role_definition(role_definition=json.dumps(incoming_role))

        else:
            # Ask if we want to update the role...
            will_update_role: bool = (
                input(f'Pre-existing role found with name "{role_name}". Update the role [Y/n]: ') != "n"
            )
            print()  # noqa: T201

            # If the role should be updated...
            if will_update_role:
                LOGGER.info('Updating existing custom role with name "%s"', role_name)
                # Update the role definition.
                update_role_definition(role_definition=json.dumps(incoming_role))

    else:
        # Create the role definition
        role_definition = create_role_definition(role_definition=json.dumps(incoming_role))

    # Return the role definition.
    return role_definition


def create_or_maybe_update_role_and_assignment(
    application_id: str, incoming_role: dict, subscription_ids: Optional[List[str]] = None
) -> None:
    """Let's create or maybe update a custom role."""

    # Grab the role name.
    role_name: str = incoming_role["Name"]
    # Grab the scope.
    scope: str = incoming_role["AssignableScopes"][0]

    # Create or update the role.
    role_definition: dict = create_or_maybe_update_role(incoming_role=incoming_role, subscription_ids=subscription_ids)

    # Grab the role ID for the created role.
    role_id: str = role_definition["name"]

    # Look for an existing role assignment.
    role_assignments = list_role_assignments(role_id=role_id, assignee_id=application_id)

    # If the role assignment doesn't exist.
    if role_assignments:
        LOGGER.info('Role assignment for "%s" already exists!', role_name)
    else:
        # Create the role assignment.
        create_role_assignment(
            role_id=role_id,
            assignee_id=application_id,
            scope=scope,
        )


def ingest_ics_roles(attempt_tenant_harvesting: bool, scope: str) -> Dict[int, dict]:
    """Ingest the ICS roles from the ICS repository, given the scope and flag for tenant-level harvesting."""

    # Create the set of roles.
    roles: Dict[int, dict] = {}

    # Declare the list of filenames.
    filenames: List[str]

    # Pick list of roles by partition.
    if CHOSEN_PARTITION == "AZURE_GOV":
        filenames = GOVERNMENT_ROLE_FILENAMES
    else:
        filenames = DEFAULT_ROLE_FILENAMES

    # For each role name...
    for role_index, role_filename in enumerate(filenames):
        # Create the URL.
        url: str = "/".join((ICS_ROLE_URL, role_filename))
        try:
            # Grab the response.
            response = requests.get(url=url)
            # Grab the role content.
            role_json: dict = response.json()

            # Grab the role name.
            role_name: str = role_json["properties"]["roleName"]
            # Prune the role name down.
            role_name_pruned = role_name.split(" (Subscription)", 1)[0]
            # Grab the role description.
            role_description: str = role_json["properties"]["description"]
            # If we are attempting tenant-level harvesting...
            if attempt_tenant_harvesting:
                # Now add it back in.
                role_name = role_name_pruned + " (Tenant)"
                # Prune the role name down.
                role_description = role_description.split(" for a given Subscription", 1)[0]
                # Now add it back in.
                role_description += " for a given Tenant."
            # Update the role name.
            role_json["properties"]["roleName"] = role_name
            # Update the role name.
            role_json["properties"]["description"] = role_description

            # Grab the permissions.
            permissions: dict = role_json["properties"]["permissions"][0]
            # Store the response.
            roles[role_index] = {
                "Name": role_name,
                "Description": role_description,
                "Actions": permissions["actions"],
                "NotActions": permissions["notActions"],
                "DataActions": permissions["dataActions"],
                "NotDataActions": permissions["notDataActions"],
                "AssignableScopes": [scope],
            }

            # Print the option.
            print(f'({role_index}) "{role_name_pruned}" from {url}')  # noqa: T201
        except requests.exceptions.RequestException:
            pass

    return roles


def extract_fingerprint(certificate_filepath: str) -> Optional[str]:
    """Given the certificate filepath, extract the fingerprint."""

    # Create the command that will extract the fingerprint.
    command: List[str] = ["openssl", "x509", "-in", certificate_filepath, "-noout", "-fingerprint"]
    # Grab the output.
    output: Optional[str] = run_shell_script(command=command)
    # If the output is found...
    if output:
        # Split the fingerprint out.
        delimited_fingerprint: str = output.partition("=")[2]
        # Now remove the delimiter.
        fingerprint: str = delimited_fingerprint.replace(":", "").rstrip()
        # Return the non-delimited fingerprint.
        return fingerprint


def configure() -> int:
    """Configure Azure Active Directory components for ICS harvesting."""

    # Let's try to configure Azure credentials for ICS usage.
    print()  # noqa: T201
    print("Let's create an Azure Application Registration for Rapid7 InsightCloudSec (ICS).")  # noqa: T201
    print()  # noqa: T201

    # Request the chosen name (with a default).
    chosen_name: str = (
        input(f"Enter the ICS Application Registration name [{DEFAULT_APPLICATION_REGISTRATION_NAME}]: ")
        or DEFAULT_APPLICATION_REGISTRATION_NAME
    )
    print()  # noqa: T201

    # Look up the service principal by chosen name...
    found_service_principals: List[dict] = list_service_principals(display_name=chosen_name)

    # Pre-declare the tenant ID.
    tenant_id: str
    # Pre-declare the service princpal.
    service_principal: dict
    # Pre-declare the password.
    password: Optional[str] = None
    # Pre-declare the certificate filenmae.
    certificate_filepath: Optional[str] = None
    # If there is a found service principal...
    if found_service_principals:
        # Grab the service principal.
        service_principal = found_service_principals[0]
        LOGGER.info('Found existing service principal with name "%s"', service_principal["appDisplayName"])
        # Pull out the tenant ID.
        tenant_id = service_principal["appOwnerOrganizationId"]
    else:
        # Declare the "use certifiate" flag...
        use_certificate: Optional[bool] = CHOSEN_USE_CERTIFICATE
        # If there is no choice incoming...
        if use_certificate is None:
            # Find out if we want to attempt to do certificate-based login....
            print()  # noqa: T201
            use_certificate = input("Will ICS use a certificate to login [Y/n]: ") != "n"
            print()  # noqa: T201

        # Let's create the service principal.
        LOGGER.info('Creating service principal with name "%s"...', chosen_name)
        service_principal = create_service_principal(display_name=chosen_name, use_certificate=use_certificate)
        # Pull out the tenant ID.
        tenant_id = service_principal["tenant"]

        # If the we want to use the certificate...
        if use_certificate:
            # Pull out the certificate filename.
            certificate_filepath = service_principal["fileWithCertAndPrivateKey"]
        else:
            # Pull out the password.
            password = service_principal["password"]

    # Pull out the display name.
    display_name: str = service_principal["displayName"]
    # Pull out the application ID.
    application_id: str = service_principal["appId"]

    # Configure the API permissions.
    configure_api_permissions(application_id=application_id)

    # Process the subscriptions.
    (subscription_id, subscription_ids) = get_subscription_id(tenant_id=tenant_id)

    # Declare the "attempt tenant harvesting" flag...
    attempt_tenant_harvesting: Optional[bool] = CHOSEN_ORGANIZATION_HARVESTING
    # If there is no choice incoming...
    if attempt_tenant_harvesting is None:
        # Find out if we want to attempt to do tenant-level harvesting....
        print()  # noqa: T201
        attempt_tenant_harvesting = input("Will ICS perform tenant-level harvesting [Y/n]: ") != "n"
        print()  # noqa: T201

    # Let's declare the scope.
    scope: str
    # If we are attempting to support tenant-level harvesting...
    if attempt_tenant_harvesting:
        # Use tenant scope.
        scope = create_management_group_scope_from_management_group_id(management_group_id=tenant_id)

        # Create the management role description.
        organization_reader: dict = {
            "Name": ORGANIZATION_READER_ROLE_NAME,
            "Description": ORGANIZATION_READER_ROLE_DESCRIPTION,
            "Actions": ORGANIZATION_READER_ACTIONS,
            "NotActions": ORGANIZATION_READER_NOT_ACTIONS,
            "DataActions": ORGANIZATION_READER_DATA_ACTIONS,
            "NotDataActions": ORGANIZATION_READER_NOT_DATA_ACTIONS,
            "AssignableScopes": [scope],
        }

        # Create or maybe update the role and role assignment.
        create_or_maybe_update_role_and_assignment(application_id=application_id, incoming_role=organization_reader)

    else:
        # Use subscription scope.
        scope = create_subscription_scope_from_subscription_id(subscription_id=subscription_id)

    # Find out which role we want to support...
    print()  # noqa: T201
    print("Which predefined ICS role should form the template for ICS access?")  # noqa: T201

    # Ingest the set of roles.
    roles: Dict[int, dict] = ingest_ics_roles(attempt_tenant_harvesting=attempt_tenant_harvesting, scope=scope)

    # Grab the role index (as a string).
    role_index_string: str = input(f"Which role do you want to use [0-{len(roles) - 1}, default 0]: ")
    print()  # noqa: T201

    # Grab the role index.
    role_index = int(role_index_string) if role_index_string else 0

    # Grab the harvester.
    harvester_role: dict = roles[role_index]

    # Create or maybe update the role and role assignment.
    create_or_maybe_update_role_and_assignment(
        application_id=application_id, incoming_role=harvester_role, subscription_ids=subscription_ids
    )

    # Let's indicate that we are done.
    print()  # noqa: T201
    print("Configuration complete!")  # noqa: T201
    print()  # noqa: T201
    print(f"Tenant ID: {tenant_id}")  # noqa: T201
    print(f"Subscription ID: {subscription_id}")  # noqa: T201
    print(f"Application Registration's display name: {display_name}")  # noqa: T201
    print(f"Application Registration's ID: {application_id}")  # noqa: T201

    # If the password was set...
    if password:
        print(f"Application Registration's password/secret: {password}")  # noqa: T201
        print("Please save these credentials for later use!")  # noqa: T201
    # If the certificate filename was set...
    if certificate_filepath:
        # Let's try to extract the fingerprint...
        fingerprint: Optional[str] = extract_fingerprint(certificate_filepath=certificate_filepath)
        # If the fingerprint was found...
        if fingerprint:
            print(f"Application Registration's certificate fingerprint: {fingerprint}")  # noqa: T201
        print(f"Application Registration's certificate and private key filepath: {certificate_filepath}")  # noqa: T201
        print("Please download save these credentials for later use!")  # noqa: T201
    print()  # noqa: T201
    return os.EX_OK


if __name__ == "__main__":
    configure()
