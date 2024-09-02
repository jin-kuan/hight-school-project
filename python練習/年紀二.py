print('.   ')
print('.  ')
print('. ')
print('.')
print('.')
print('.')
print('.')
print('.')
print('.')
print('請輸入現在年分與月份')
print('.')
a=int(input('    輸入西元年:'))
b=int(input('    輸入月份:'))
e=int(input("    輸入日期:"))
print('請輸入你生年分與月份:')
print('. ')
c=int(input('    輸入西元年:'))
d=int(input('    輸入月份:'))
f=int(input("    輸入日期:"))

if(b<d):
    if(e==f):
        print(a-c-1,'歲',12-(d-b),'個月')
    elif(e>f):
        print(a-c-1,'歲',12-(d-b),'個月又',e-f,'天')
    else:
        print(a-c-1,'歲',12-(d-b)-1,'個月又',30-(e-f),'天')
elif(b>d):
    if(e==f):
        print(a-c,'歲',b-d,'個月')
    elif(e>f):
        print(a-c,'歲',b-d,'個月又',e-f,'天')
    else:
        print(a-c,'歲',b-d-1,'個月又',30-(e-f),'天')

else:
    if(e==f):
        print(a-c,'歲')
    elif(e>f):
        print(a-c,'歲',e-f,'天')
    else:
        print(a-c,'歲',30-(e-f),'天')
    

    

