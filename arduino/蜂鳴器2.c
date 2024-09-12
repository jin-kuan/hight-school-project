int buzzPin =9;
void setup(){    
    pinMode(buzzPin, OUTPUT);
}

void loop(){
    tone(buzzPin,442);
    delay(1000);
    tone(buzzPin,0);
    delay(1000);
}