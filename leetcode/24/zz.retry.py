import requests
from requests.adapters import HTTPAdapter
from urllib3.util import Retry
from tenacity import retry, stop_after_attempt, wait_exponential

retry_strategy = Retry(
    total=4,
    backoff_factor=2,
    status_forcelist=[429, 500, 502, 503, 504],
)
adapter = HTTPAdapter(max_retries=retry_strategy)
 
session = requests.Session()
session.mount('http://', adapter)
session.mount('https://', adapter)
 
response = session.get('https://scrapingcourse.com/ecommerce/')
 
if response.status_code == 200:
    print(f'SUCCESS: {response.text}')
else:
    print("FAILED")
 
def retry_request(url, total=4, status_forcelist=[429, 500, 502, 503, 504], **kwargs):
    # Make number of requests required
    for _ in range(total):
        try:
            response = requests.get(url, **kwargs)
            if response.status_code in status_forcelist:
                # Retry request 
                continue
            return response
        except requests.exceptions.ConnectionError:
            pass
    return None
 
response = retry_request('https://scrapingcourse.com/ecommerce/')
print(response.text)

def backoff_delay(backoff_factor, attempts):
    # backoff algorithm
    delay = backoff_factor * (2 ** attempts)
    return delay

# Define the retry decorator
@retry(
    stop=stop_after_attempt(4), # Maximum number of retries
    wait=wait_exponential(multiplier=1, min=1, max=60) # Exponential backoff
)
def make_request(data):
    return requests.post('https://scrapingcourse.com/ecommerce/')
 
try:
    response = make_request({ 'key': 'value' })
    print(f'SUCCESS: {response.text}')
except requests.RequestException as e:
    print(f'FAILED: {e}')