def getan(n):
    if n == 1:
        return al
    else:
        return getan(n-1)+d*(n-1)+al

al = int(input("首項"))
d = int(input("公比"))
n = int(input("項數"))
sum1=0

for i in range(n):
    print(al+d*i)
    sum1=al+d*i+sum1

print()

print(sum1)
print()
print(getan(n))
