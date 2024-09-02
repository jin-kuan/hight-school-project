def sec_to_bin(num):
    result=[]
    while True:
        num,reminder=divmod(num,8)
        result.append(str(reminder))
        if num == 0:
            return "".join(result[::-1])
    

testNum = int(input("int:"))
ans = sec_to_bin(testNum)
print(ans)

