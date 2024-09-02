strmsg="12 5 6 7 8 9"
strlist=strmsg.split()
print(strlist)
mapobj=map(int,strlist)
intlist=list(mapobj)
print(intlist)
print(sum(intlist))