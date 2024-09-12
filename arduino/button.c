int buttonState;
int buttonPin = 2;
int ledPin = 9;

void setup() {
    pinMode(buttonPin, INPUT);
    pinmode(ledPin, OUTPUT);
}

void loop() {
    buttonState = digitalRead(buttonPin);

    if(buttonState == HIGH){
        digitalWrite(ledPin,HIGH);
    }
    else{
        digitalWrite(ledPin, LOW);
    }
}
