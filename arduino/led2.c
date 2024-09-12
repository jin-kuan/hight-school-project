int buttonState;
int buttonPin = 9;
int ledPin = 10;
void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin,INPUT);
}

void loop()
{
    buttonState=digitalRead(buttonPin);
    if(buttonState==HIGH){
        digitalWrite(ledPin, HIGH);
    }
    else{
        igitalWrite(ledPin, LOW);
    }
    
}
