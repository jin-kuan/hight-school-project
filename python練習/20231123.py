import random
hotel=[0]*10
b=0
for i in range(0,10):
    hotel[i]=random.randint(100,1000)
print(hotel)
for i in range(0,10):
    if(hotel[i]>hotel[b]):
        b=i
print(b+1)
print(hotel[b]) 