import requests
from bs4 import BeautifulSoup
import queue
import re
import time
import random

urls = queue.PriorityQueue()
urls.put((0.5, "https://scrapeme.live/shop/"))
visited_urls = []

while not urls.empty():
    _, current_url = urls.get()

    response = requests.get(current_url)
    soup = BeautifulSoup(response.content, "html.parser")

    visited_urls.append(current_url)

    link_elements = soup.select("a[href]")
    for link_element in link_elements:
        url = link_element['href']

        if re.match(r"https://(?:.*\.)?scrapeme\.live", url):
            if url not in visited_urls and url not in [item[1] for item in urls.queue]:
                priority_score = 1
                if re.match(r"^https://scrapeme\.live/shop/page/\d+/?$", url):
                    priority_score = 0.5
                urls.put((priority_score, url))
    time.sleep(random.uniform(1, 3)) 
