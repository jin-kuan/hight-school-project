a=int(input())
for i in range(a):
    b[i]=int(input())

if max(b)<60:
    print("可憐阿")
if min(b)>=60:
    print("厲害喔")

sorted(b)
for i in range(a):
    if b[i]>=60:
        print(b[i])
for i in range(a,-1):
    if b[i]<60:
        print(b[i]) 