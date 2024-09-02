
def getsum(n):
    if n == 1 or n == 0:
        return 0
    else:
        return(n-1)+n*(n-1)
    

n=int(input("N:"))

sum1 = 0
for i in range(2,n+1):
    ai = (i - 1) * i
    sum1 += ai
    print(f"{i-1}*{i}",end="  ")


print("=",sum1)

print("\n========================================\n")
ans=getsum(n)
print(ans)


