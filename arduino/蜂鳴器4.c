int a[63]={4,2,2,4,2,2,2,2,2,2,8,4,2,2,4,2,2,2,2,2,2,8,4,6,2,2,2,2,2,6,2,2,2,2,2,6,2,2,2,2,2,6,2,2,2,2,2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,8};
int b[63]={525,0,393,525,0,393,525,393,525,661,786,701,0,590,701,0,590,701,590,497,590,393,525,525,662,590,525,525,497,497,590,701,497,590,525,525,625,590,525,	525,497,497,590,701,497,525,525,525,497,442,497,525,525,662,590,525,590,662,662,786,701,662,701,786};

int buzzPin=2;

void setup() {
  digitalWrite(buzzPin,OUTPUT);

}
void loop() {
   for(int i=0;i<63;i++){
    tone(buzzPin,b[i]);
    delay(a[i]*250);
   }
}