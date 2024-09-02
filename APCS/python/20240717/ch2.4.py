h=int(input("輸入身高"))
k=int(input("輸入體重"))

# 計算BMI

bmi=k/(h/100)**2*100
bmi=int(bmi)
print("BMI:",bmi%10000,end="")
# print(bmi%1000,end=".")
# print(bmi%100,end=".")
# print(bmi%10,end=".")
