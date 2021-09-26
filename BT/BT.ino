#include <SoftwareSerial.h>

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(8, 9); // RX, TX
char val;

void setup() {
  Serial.begin(9600);
  Serial.println("BT is ready!");

  // 如果是HC-05改成38400
  BT.begin(38400);
}

void loop() {
  if (Serial.available()>0) {
    val = Serial.read();
    BT.print(val);
    Serial.println(val);
  }

  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
  }
}
