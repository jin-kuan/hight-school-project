temp = {0:0,1:1}
def fid(n):
    if n == 0 or n == 1:
        return (n)
    else:
        return fid(n-1) + fid(n-2)

def fid2(n):
    if n in temp:
        return temp[n]

    else:

        key1 = n - 1
        key2 = n - 2
        if key1 in temp:
            v1 = temp[key1]
        else:
            v1 = fid2(key1)
            temp[key1] = v1
        if key2 in temp:
            v2 = temp[key2]
        else:
            v2 = fid2(key2)
            temp[key2] = v2
        
        return v1 + v2
while 1:
    y = int(input("num:"))
    ans = fid2(y)
        
    print(ans)
