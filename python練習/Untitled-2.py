a=int(input('性別:男生是1女生是2'))
b=int(input('年齡'))

if(a>=1):
    if(b>=30):
        print("適婚")
    else:
        print('不適合')
else:
    if(b>=20):
        print('適婚')
    else:
        print('不適合')        


