#include <SoftwareSerial.h>

// 定義連接藍牙模組的序列埠
int LED = 9;
SoftwareSerial BT(2, 15); // RX, TX

char val;
String Word;
long V=0;

void setup() {
  Serial.begin(9600);
  Serial.println("BT is ready!");
  pinMode(LED,OUTPUT);
  digitalWrite(LED,1);
  // 如果是HC-05改成38400
  BT.begin(9600);
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
    BT.print(val);
    Serial.println(val);
  }

  if (BT.available()) {
    Word = BT.readString();
    BT.println(Word);  
  }
}
