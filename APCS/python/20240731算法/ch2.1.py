def sec_to_bin(num):
    result=[]
    while True:
        num,reminder=divmod(num,2)
        result.append(str(reminder))
        if num == 0:
            return "".join(result[::-1])

def dec_to_hex(num):
    base = ["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"]
    result = []
    while True:
        num,reminder = divmod(num,16)
        result.append(base[reminder])
        if num == 0:
            return "".join(result[::-1])
    

testNum = int(input("int:"))
ans = dec_to_hex(testNum)
print(ans)
