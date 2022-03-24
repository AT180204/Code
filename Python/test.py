from urllib import response
import requests

res = requests.get('http://mercury.picoctf.net:15931/')
res.encoding = 'utf-8'
print(res.text)