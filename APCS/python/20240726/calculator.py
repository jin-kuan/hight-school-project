pi = 3.14159

def calcArea(r):
    return pi*r*r

def toFahrenheit(tempC):
    return 9/5*tempC + 32
    
def calcBmi(height, weight):
    return weight/(height/100)**2

def getMessage(bmi):
    if bmi <= 18.5:
        message ='您的體重過輕'
    elif 25> bmi > 18.5 :
        message ='您的體重正常'
    elif bmi >= 25 and bmi < 30:
        message ='您的體重過重'
    elif bmi > 30:
        message ='您的體重肥胖'
    return message
