n=int(input('輸入n'))
b=[0]*n
g=0
for i in range(n):
    b[i]=int(input('成績'))
print(b)

for i in range(n):
    g=g+b[i]
print(g/n)

for i in range(n):
    if(b[i]<60):
        print(i+1,'號',b[i],'分') 
b.sort()
print(b,'   ',b[0],'   ',b[-1])

