'''
x = [5,15,25,35,45]
n=len(x)

while n>0:
    v=x.pop()
    print(v)
    n=n-1
    
'''
def myMin(mylist):
    max1=100
    for i in range(3):
        if mylist[i]<max1:
            max1=mylist[i]
    return max1
def myMax(mylist):
    max1=0
    for i in range(3):
        if mylist[i]>max1:
            max1=mylist[i]
    return max1
n=3
scores = []
for i in range(n):
    s = int (input(f"{i+1}比成績"))
    scores.append(s)
print(scores)

ans=myMin(scores)
print(ans)
