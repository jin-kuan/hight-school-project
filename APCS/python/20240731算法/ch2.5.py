def getan(n):
    if n ==1:
        return al
    else:
        return getan(n-1)+al*d**(n-1)
al = int(input("首項"))
d = int(input("公比"))
n = int(input("項數"))
sum1=0

for i in range(n):
    sum2=al*d**i
    print(sum2)
    sum1=sum1+sum2

print(sum1)
print(getan(n))
