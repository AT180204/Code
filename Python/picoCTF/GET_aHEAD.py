import requests

res = requests.head('http://mercury.picoctf.net:15931/')

print(res.headers)