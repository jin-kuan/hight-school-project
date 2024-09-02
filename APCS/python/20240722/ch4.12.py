try:
    for i in range(1,5):
        for j in range(1,4):
            print(i,"_",j,end="  ")
            if i==2:
                raise Excption()
        print()
except:
    pass