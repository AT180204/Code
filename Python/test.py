from urllib import response
import requests

response = requests.get('http://mercury.picoctf.net:15931/')
response.encoding = 'utf-8'
print(response.text)