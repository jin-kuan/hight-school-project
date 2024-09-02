num =int(input("Enter a number: "))
a=True
for i in range(1,num+1):
    if num%i==0:
        print(i)
        a=False
        
if a==False:
    print("不是質數")
else:
    print("是質數")