a=[50,25,76,38,19,58]
max=0
for b in range(1,7):
    for i in range(1,b):
        if(a[max]<a[i]):
            max=i
        print(a[max])

