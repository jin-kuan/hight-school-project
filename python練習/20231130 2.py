b=[50,60,76,38,18,58]
for c in range(6):
    for f in range(5-c):
        if b[f]>b[f+1]:
            p=b[f]
            b[f]=b[f+1]
            b[f+1]=p
print(b)