a=15
def func():
    global a
    a=a+1
    print("func(: a=)",a)
print(a)
func()
print(a)