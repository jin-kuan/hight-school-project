#等公車
h=int(input("現在時間"))
if(h>25):
    print(60-h+25)
elif(h<25):
    print(25-h)
elif(h<60):
    print('呵呵')
else:
    print('即將到站')

