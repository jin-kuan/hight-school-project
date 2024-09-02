n=int(input('N'))
s=int(input('s'))
x=0
for i in range (1,n+1,1):
    if((i % 10)==s):
        print(i)
        x=x+1
print('共',x,'個')
