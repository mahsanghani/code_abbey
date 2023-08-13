#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int i, j, main_exit;
void menu();

struct date {
	int month, day, year;
};

struct {
	char name[60];
	int age, acc_no;
	char address[60];
	char citizenship[15];
	double phone;
	char acc_type[10];
	float amt;
	struct date dob;
	struct date deposit;
	struct date withdraw;
} add, upd, rem, check, transaction;

float interest(float t, float amount, int rate) {
	float SI;
	SI = (rate * t * amount) / 100.0;
	return (SI);
}

void fordelay(int j) {
	int i, k;
	for (int i = 0; i < j; i++) {
		k = i;
	}
}

void new_acc() {
	int choice;
	FILE* ptr;

	ptr = fopen("record.dat", "a+");
	account_no;
	system("cls");

	printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
	printf("\n\n\nEnter today's date(mm/dd/yyyy):");
	scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
	printf("\nEnter the account number:");
	scanf("%d", &check.acc_no);
	while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
	{
		if (check.acc_no == add.acc_no)
		{
			printf("Account no. already in use!");
			fordelay(1000000000);
			goto account_no;

		}
	}

	add.acc_no = check.acc_no;
	print("\nEnter the name:");

	scanf("%s", add.name);
	printf("\nEnter the date of birth(mm/dd/yyyy):");
	scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
	printf("\nEnter the age:");
	scanf("%d", &add.age);
	printf("\nEnter the address:");
	scanf("%s", add.address);
	printf("\nEnter the citizenship number:");
	scanf("%s", add.citizenship);
	printf("\nEnter the phone number: ");
	scanf("%lf", &add.phone);
	printf("\nEnter the amount to deposit:$");
	scanf("%f", &add.amt);
	printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
	scanf("%s", add.acc_type);

	fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);


	fclose(ptr);
	printf("\nAccount created successfully!");
add_invalid:
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);

	system("cls");
	if (main_exit == 1) {
		menu();
	}
	else if (main_exit == 0) {
		close();
	}
	else {
		printf("\nInvalid!\a");
		goto add_invalid;
	}
}

void view_list() {
	FILE* view;
	view = fopen("record.dat", "r");
	int test = 0;
	system("cls");
	printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

	while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
	{
		printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
		test++;
	}

	fclose(view);
	if (test == 0) {
		system("cls");
		printf("\nNO RECORDS!!\n");
	}

view_list_invalid:
	printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1) {
		menu();
	}
	else if (main_exit == 0) {
		close();
	}
	else {
		printf("\nInvalid!\a");
		goto view_list_invalid;
	}
}