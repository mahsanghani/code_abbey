import requests
from bs4 import BeautifulSoup
import queue
import re
import time
import random

urls = queue.PriorityQueue()
urls.put((0.5, "https://scrapeme.live/shop/"))
visited_urls = []
products = []

def get_html(url): 
    try: 
        return requests.get(url).content 
    except Exception as e: 
        print(e) 
        return ''

def scrape_page(soup, url, products): 
    product = {}
    product["url"] = current_url
    product["image"] = soup.select_one(".wp-post-image")["src"]
    product["name"] = soup.select_one(".product_title").text()
    product["price"] = soup.select_one(".price")
    products.append(product)

def crawl_page(soup, url, visited_urls, urls): 
    link_elements = soup.select("a[href]")
    for link_element in link_elements:
        url = link_element['href']
    
        if re.match(r"https://(?:.*\.)?scrapeme\.live", url):
            if url not in visited_urls and url not in [item[1] for item in urls.queue]:
                priority_score = 1
                if re.match(r"^https://scrapeme\.live/shop/page/\d+/?$", url):
                    priority_score = 0.5
                urls.put((priority_score, url))

while not urls.empty():
    _, current_url = urls.get()
    soup = BeautifulSoup(get_html(current_url), "html.parser")

    visited_urls.append(current_url)
    crawl_page(soup, current_url, visited_urls, urls)

    # if it is a product page:
    scrape_page(soup, urls, products)
time.sleep(random.uniform(1, 3))
