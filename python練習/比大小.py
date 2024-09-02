p=int(input("數量"))
a=[0]*p
max=0
c=0
for i in range(p):
    a[i]=int(input('號碼'))
for y in range(p):

    for v in range(y):
        if a[v]>a[v+1]:
            c=a[v]
            a[v]=a[v+1]
            a[v+1]=c
    
print(a)        


  
