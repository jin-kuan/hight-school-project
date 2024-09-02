answer=['a','c','c','a','d','b','b']
a=[0]*6
b=0

for i in range(6):
    a[i]=input('答案')
for i in range(6):
    if answer[i]==a[i]:
        b=b+1
print('答對',b,'提   ','答錯',7-b,'題')
