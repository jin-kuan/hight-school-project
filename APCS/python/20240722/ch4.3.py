list1=[1,2,3,4,8,13,21,55,89]
print(list1)
filterObj=filter(lambda x : x%2==0,list1)
print(list(filterObj))