import requests

response = requests.request("GET", url='https://book.whsh.tc.edu.tw/books/python%E6%95%99%E5%AD%B8/page/2-6b')#可直接用request函式並在參數內選擇方法(get,post)

print(response.text)  #印出資料，也就是文字版的網頁
