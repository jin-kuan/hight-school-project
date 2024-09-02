n=int(input('選課人數'))
b=[0]*9
a=[0]*n
c=0
l=0
u=0
y=0
t=0
r=0
f=0
e=0
p=0



for i in range(n):
    print('第',i+1,'位的自願')
    a[i]=int(input())
for i in range(n):
    if a[i]==1:
        c=c+1
    elif a[i]==2:
        l=l+1
    elif a[i]==3:
        u=u+1
    elif a[i]==4:
        y=y+1 
    elif a[i]==5:
        t=t+1
    elif a[i]==6:
        r=r+1
    elif a[i]==7:
        f=f+1
    elif a[i]==8:
        e=e+1
    

b[1]=c
b[2]=l
b[3]=u
b[4]=y
b[5]=t
b[6]=r
b[7]=f
b[8]=e

print(a)
for i in range(n):
    print('第',i+1,'門課又',a[i],'人選')






