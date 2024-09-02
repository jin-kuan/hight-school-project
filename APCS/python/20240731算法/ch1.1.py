def funcl(x):
    print("s:",x)
    if x<=4:
        print(x)
        funcl(x+1)
    print("end:",x)

funcl(1)
