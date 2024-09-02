import math
b = int(input("N"))
p = []
def a1(n):
    for i in range(2,n+1):
        c = 0
        for j in range(2,i):
            if j**2 >i:
                break
            elif i % j==0:
                c = c+1
        if  c == 0:
            p.append(i)

    print(p)

def a2(n):
        for i in range(2,n+1):
            f = 0
            for j in range(2,int(math.sqrt(i)+1)):
                if i % j==0:
                    f = f+1
                if  f == 0:
                    p.append(i)
        print(p)
    

a1(b)
print()
print("="*30)
print()
a2(b)
