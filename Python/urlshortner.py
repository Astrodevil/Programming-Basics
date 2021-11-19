import urllib
import requests
import json


def shorten(link):
    key = '' # Your cutt.ly api key
    url = urllib.parse.quote(link)
    r = requests.get(f'http://cutt.ly/api/api.php?key={key}&short={url}')
    y = json.loads(r.text)
    return y['url']['shortLink']

url = input("Enter url you want to shorten=>")
print("Your shortened url:", shorten(url))
