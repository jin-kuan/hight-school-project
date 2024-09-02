def fid(n):
    if n==0 or n==1:
        return n
    else:
        num1=0
        num2=1

        nextnum=num1+num2
        for i in range(2,n):
            num1=num2
            num2=nextnum
            nextnum=num1+num2
        return nextnum

ans=fid(8)
print(ans)
        
