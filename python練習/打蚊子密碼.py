N=int(input("N"))
s=int(input('s'))
num=0
for i in range(0,N+1,1):
    if(i % 10==s):
        num=num+1
        print(i)
print(num)
