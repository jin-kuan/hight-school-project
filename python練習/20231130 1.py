a=int(input('人數'))
b=[0]*a
for i in range(a):
    b[i]=int(input('成績'))
for c in range(a):
    for f in range(a-1-c):
        if b[f]<b[f+1]:
            p=b[f]
            b[f]=b[f+1]
            b[f+1]=p
print(b)

 