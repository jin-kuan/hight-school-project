import locale
print(locale.getpreferredencoding())
f1=open("Poem.txt",encoding="cp950")
line=f1.readline()
while line:
    print(line,end="")
    line=f1.readline()