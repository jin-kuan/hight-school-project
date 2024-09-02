import random
e=[0]*100

for i in range(0,100):
    e[i]=random.randint(75,100)
for y in range(99):

    for v in range(100-1-y):
        if e[v]<e[v+1]:
            c=e[v]
            e[v]=e[v+1]
            e[v+1]=c

print(e)