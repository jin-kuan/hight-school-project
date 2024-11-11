int bottonPin1=2;//頻率加2
int bottonPin2=3;//頻率減2
int sum=442;//頻率
int berPin=4;
int bottonA=0;
int bottonB=0;




void setup() {
  pinMode(bottonPin1,INPUT);
  pinMode(bottonPin2,INPUT);
  pinMode(berPin,OUTPUT);
  Serial.begin(115200);

}

void loop() {
  


  

    Serial.println(sum);
    tone(berPin,sum);

    bottonA=digitalRead(bottonPin1);
    bottonB=digitalRead(bottonPin1);
    if(bottonA==HIGH){
      sum=sum+2;
    }
    if(bottonB==HIGH){
      sum=sum-2;
    }
    delay(100);

  
}
