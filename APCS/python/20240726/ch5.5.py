from calculator import calcBmi,getMessage

h=180
w=70
bmi=calcBmi(h,w)
message=getMessage(bmi)
print(f"{bmi:.2f}",message)