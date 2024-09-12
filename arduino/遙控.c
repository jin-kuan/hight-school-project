#include <WiFi.h>
#include <WebServer.h>

const char* ssid= "哈哈哈";
const char* password="12345678";

int leftPin1=2;
int rightPin1=3;
int leftPin2=4; 
int rightPin2=5;

int V1=255;
int V2=255;

WebServer server(80);

void front(){
  digitalWrite(leftPin1,V1);
  digitalWrite(leftPin2,0);
  digitalWrite(rightPin1,V2);
  digitalWrite(rightPin2,0);
}

void back(){
  digitalWrite(leftPin1,0);
  digitalWrite(leftPin2,V1);
  digitalWrite(rightPin1,0);
  digitalWrite(rightPin2,V2);
}

void left(){
  digitalWrite(leftPin1,0);
  digitalWrite(leftPin2,V1);
  digitalWrite(rightPin1,V2);
  digitalWrite(rightPin2,0);
}

void right(){
  digitalWrite(leftPin1,V1);
  digitalWrite(leftPin2,0);
  digitalWrite(rightPin1,0);
  digitalWrite(rightPin2,V2);
}

void stop(){
  digitalWrite(leftPin1,0);
  digitalWrite(leftPin2,0);
  digitalWrite(rightPin1,0);
  digitalWrite(rightPin2,0);
}

void handelRoot(){
  String HTML=  "<!DOCTYPE html>\
  <html>\
  <head><meta charset='utf-8'></head>\
  <body>\
  哈哈哈\
  <script>var xhttp= new XMLHttpRequest();\
          function sw(arg){\
              xhttp.open('GET', '/sw?led=' + arg, true);\
              xhttp.send()}\
  </script>\
  <button onmousedown=sw('stop')>前進</button>\
  <button onmousedown=sw('fromf')>關燈</button>\
  <button onmousedown=sw('back')>前進</button>\
  <button onmousedown=sw('right')>關燈</button>\
  <button onmousedown=sw('left')>前進</button>\
  </body>\
  </html>";
  server.send(200,"text/html",HTML);
}

void ledSwitch(){
  String state=server.arg("led");

  if(state == "stop"){
    stop();
  } else if(state == "front"){
    front();
  } else if(state == "back"){
    back();
  } else if(state == "right"){
    right();
  } else if(state == "left"){
    left();
  }
  
  server.send(200,"text/html","led is <b>"+state+"</b>.");
}

void setup() {
  pinMode(leftPin1,OUTPUT);
  pinMode(leftPin2,OUTPUT);
  pinMode(rightPin1,OUTPUT);
  pinMode(rightPin2,OUTPUT);

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nIP:");
  Serial.println(WiFi.localIP());
    
  server.on("/",handelRoot);
  server.on ("/sw",ledSwitch);
  // server.on("/hello",{server.send(200,"text/html","hello");});
  //  server.onNotFound({ server.send(200, "text/html;charset=utf-8", "找不到" );});
  server.begin();
}

void loop() {
  server.handleClient();
}
