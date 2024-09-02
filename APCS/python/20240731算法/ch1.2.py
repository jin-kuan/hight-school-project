def func2(x):
    print("s:",x)
    if x<=3:
        print(x)
        v=func2(x+1)+func2(x+2)
        print("v:",v)
    print("e:",x)
    return x
func2(1)
