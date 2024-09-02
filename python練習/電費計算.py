while True:

    num = int(input('輸入用電度數:'))

    if num<=100:

        print('用電',num,'度  共',num*1.5,'元')
        


    elif num <=500:

        print('用電',num,'度  共',150+(num-100)*2.5,'元')
        


    elif num <=1000:

        print('用電',num,'度  共',150+400*2.5+(num-500)*3.5,'元')
        


    else:

        print('用電',num,'度  共',150+400*2.5+500*3.5+(num-1000)*10,'元')
        


