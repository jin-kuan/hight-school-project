subjs=["國文","數學","英文"]
scores=[100,80,90]
print(len(scores),len(subjs))
for i in range(len(subjs)):
    print(subjs[i],scores[i])

print("="*50)

for n,s in zip(subjs,scores):
    print(n,s)