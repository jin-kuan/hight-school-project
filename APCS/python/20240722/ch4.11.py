def testage(age):
    if age<0 or age>=200:
        # print(age)
        raise Exception("錯誤")
    else:
        print(age)
testage(999)
