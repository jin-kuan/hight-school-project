int buzzPin =9;
void setup(){    
    pinMode(buzzPin, OUTPUT);
}

void loop(){
    digitalWrite(buzzPin,HIGH);
    delay();
    digitalWrite(buzzPin, LOW);
    delay(1);
}