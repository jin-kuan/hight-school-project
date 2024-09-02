import time

print(time.time())
time.sleep(2)
print(time.ctime())
time.sleep(2)
lt=time.localtime()
print(lt)
print(lt.tm_year,lt.tm_mon,lt.tm_mday)