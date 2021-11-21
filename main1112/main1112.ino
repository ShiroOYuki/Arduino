#include <EEPROM.h>
#include <SoftwareSerial.h>

int trigPin = 10;
int echoPin = 9;

int choose[6] = {12,13,14,15,11};

int Pin_A = 16;
int Pin_B = 17;
int Pin_C = 18;
int Pin_D = 19;

int latchPin = 4;
int clockPin = 3;
int dataPin = 2;

int btns[5] = {5,6,7,8};

int BT_RX = 1;
int BT_TX = 0;
SoftwareSerial BTSerial(BT_TX,BT_RX); // RX | TX

long ct = 0;
float distance = 100;
int level = 8;
int warning = 10;
long blinkCt = 0;
int blinkStatu = 0;
String displayMode = "current";
int ld = 0;
int sd = 0;
int dv;
int levelRange = 4;
int btnSendStatus[5] = {0,0,0,0};
int IsGetDistance = 1;
long btt;


void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  for (int i=0;i<5;i++){
    pinMode(choose[i],OUTPUT);
  }
  
  for (int i=0;i<4;i++){
    pinMode(btns[i],INPUT);
  }

  pinMode(Pin_A,OUTPUT);
  pinMode(Pin_B,OUTPUT);
  pinMode(Pin_C,OUTPUT);
  pinMode(Pin_D,OUTPUT);

  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);

  
  EEPROM.get(30,dv);
  EEPROM.put(0,dv);
  
  BTSerial.begin(9600);
}

void loop() {
  // Get Distance
  if (millis() - ct >= 100 && IsGetDistance == 1){
    distance = getDistance();
    int d10 = distance * 10;
    EEPROM.get(30,ld);
    EEPROM.get(10,sd);
    EEPROM.put(10,ld);
    EEPROM.put(30,d10);
    level = distance / levelRange;
    if (level > 8){
      level = 8;
    }
    if (distance >= warning){
      IC_74595(255>>level);
    }
    ct = millis();
    Serial.print("d;");
    Serial.println(distance);
  }

  // Blink
  if (distance <= warning){
    if (millis() - blinkCt >= 100*level){
      if (blinkStatu == 0){
        IC_74595(0);
        blinkStatu = 1;
      }
      else{
        IC_74595(255>>level);
        blinkStatu = 0;
      }
      blinkCt = millis();
    }
  }

  // Btn
  if (digitalRead(btns[0]) == 1 && btnSendStatus[0] == 0) {
    displayMode = "last";
    btnSendStatus[0] = 1;
    Serial.println("sw1P");
  }
  else if (digitalRead(btns[0]) == 0 && btnSendStatus[0] == 1){
    btnSendStatus[0] = 0;
    Serial.println("sw1R");
  }
  if (digitalRead(btns[1]) == 1 && btnSendStatus[1] == 0) {
    displayMode = "second";
    btnSendStatus[1] = 1;
    Serial.println("sw2P");
  }
  else if (digitalRead(btns[1]) == 0 && btnSendStatus[1] == 1){
    btnSendStatus[1] = 0;
    Serial.println("sw2R");
  }
  if (digitalRead(btns[2]) == 1 && btnSendStatus[2] == 0) {
    displayMode = "minus";
    btnSendStatus[2] = 1;
    Serial.println("sw3P");
  }
  else if (digitalRead(btns[2]) == 0 && btnSendStatus[2] == 1){
    btnSendStatus[2] = 0;
    Serial.println("sw3R");
  }
  if (digitalRead(btns[3]) == 1 && btnSendStatus[3] == 0) {
    displayMode = "current";
    IsGetDistance = 1- IsGetDistance;
    btnSendStatus[3] = 1;
    Serial.println("sw4P"); 
    btt = millis();
  }
  else if (digitalRead(btns[3]) == 0 && btnSendStatus[3] == 1){
    btnSendStatus[3] = 0;
    Serial.println("sw4R");
  }

  if (displayMode == "last"){
    segLight(dv);
  }
  else if (displayMode == "second"){
    segLight(sd);
  }
  else if (displayMode == "minus"){
    int md = 0;
    md = dv - sd;
    if (md<0){
      md = 0-md;
    }
    segLight(md);
  }
  else if (displayMode == "current"){
    segLight(distance * 100);
  }
  
  // Serial
  if (Serial.available() > 0){
    String inp = Serial.readString();
    String mode = getValue(inp,';',0);
    String data = getValue(inp,';',1);
    Serial.println("Serial Read");
    if (mode == "changeWarning"){
      warning = data.toInt();
    }
    else if (mode == "changeLevelRange"){
      levelRange = data.toInt();
    }
    else if (mode == "getBtnStatus"){
      Serial.println(displayMode);
    }
    else if (mode == "SW1"){
      displayMode = "last";
    }
    else if (mode == "SW2"){
      displayMode = "second";
    }
    else if (mode == "SW3"){
      displayMode = "minus";
    }
    else if (mode == "SW4"){
      displayMode = "current"; 
      IsGetDistance = 1- IsGetDistance;
    }
    else if (mode == "send"){
      BTSerial.print(data);
    }
    else{
      Serial.println("else."+inp);
    }

    // BT
//    if (BTSerial.available()){
//      String indata = BTSerial.readString();
//      Serial.println("BT Read");
//      Serial.println(indata);
//    }
  }
}

float getDistance(){
  float distance,receiveTime;
  digitalWrite(trigPin,1);
  delayMicroseconds(10);
  digitalWrite(trigPin,0);
  
  receiveTime = pulseIn(echoPin,1);

  distance = (receiveTime/2)/29.1;

  return distance;
}

void segLight(int id){
  for (int i=4;i>-1;i--){
    digitalWrite(choose[i],0);
    IC_CD4511(id%10);
    id /= 10;
    delay(5);
    digitalWrite(choose[i],1);
  }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
      if (data.charAt(i) == separator || i == maxIndex) {
          found++;
          strIndex[0] = strIndex[1] + 1;
          strIndex[1] = (i == maxIndex) ? i+1 : i;
      }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void IC_74595(int data){
  digitalWrite(latchPin,0); //送資料前要先把 latchPin 設成低電位
  shiftOut(dataPin, clockPin, LSBFIRST, data); //送出資料，例如輸入170，就是2進位的10101010 -> 8顆LED燈會照這樣亮
  digitalWrite(latchPin,1); // 送完資料後要把 latchPin 設成高電位
} 

void IC_CD4511(int val){
  int D=0,C=0,B=0,A=0;
  for(int i=0;i<val;i++){
    if(A==0)
      A=1;
    else{
      A=0;
      if(B==0)
        B=1;
      else{
        B=0;
        if(C==0)
          C=1;
        else{
          C=0;
          if(D==0)
            D=1;
          else
            D=0;
        }
      }
    }
  }
  digitalWrite(Pin_A,A);
  digitalWrite(Pin_B,B);
  digitalWrite(Pin_C,C);
  digitalWrite(Pin_D,D);
}
