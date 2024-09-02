import random
answer=random.randint(1,100)
g=int(input("數字"))
min=1
max=100
while True:
    if g==answer:
        print("答對了")
        break
    elif g>answer:
        max=g
    elif g<answer:
        min=g
    g=int(input(f"在猜一次:({min}~{max}):"))