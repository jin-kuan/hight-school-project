def getan(n):
    if n == 1:
        return al
    else:
        return getan(n-1)*d

al = int(input("首項"))
d = int(input("公比"))
n = int(input("項數"))

for i in range(n):
    print(al*d**i,end=" ")

print()
print(getan(n))
