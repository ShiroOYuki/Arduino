#include <SoftwareSerial.h>

// 定義連接藍牙模組的序列埠
int LED = 9; //測試是否完成寫入用
int LED_Control = 11;
SoftwareSerial BT(8, 10); // RX, TX

char val;
String Word;
float distance;
int trig = 7;
int echo = 6;

void setup() {
  Serial.begin(9600);
  Serial.println("BT is ready!");
  pinMode(LED,OUTPUT);
  pinMode(LED_Control,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  digitalWrite(LED,1);
  // HC-05 "有可能"是 38400，但建議先用 AT+UART? 查查
  BT.begin(9600);
}

void loop() {

  delay(500);

  distance = getDistance(trig,echo);

  BT.println(distance);  
  
  if (Serial.available()) {
    val = Serial.read();
    BT.print(val);
    Serial.println(val);
  }

  if (BT.available()) {
    Word = BT.readString();
    
    BT.println(Word);  
    Serial.print(Word);
  }
}

float getDistance(int trigPin,int echoPin){
  float distance,receiveTime;
  digitalWrite(trigPin,1);
  delayMicroseconds(10);
  digitalWrite(trigPin,0);
  
  receiveTime = pulseIn(echoPin,1);

  distance = (receiveTime/2)/29.1;

  return distance;
}
