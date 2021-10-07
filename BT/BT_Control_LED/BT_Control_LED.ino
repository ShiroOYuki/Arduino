#include <SoftwareSerial.h>

// 定義連接藍牙模組的序列埠
int LED = 9; //測試是否完成寫入用
int LED_Control = 11;
SoftwareSerial BT(8, 10); // RX, TX

char val;
String Word;
long V=0;

void setup() {
  Serial.begin(9600);
  Serial.println("BT is ready!");
  pinMode(LED,OUTPUT);
  pinMode(LED_Control,OUTPUT);
  digitalWrite(LED,1);
  // HC-05 "有可能"是 38400，但建議先用 AT+UART? 查查
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
    if(Word == "On\r\n"){//CR+LF 的輸入模式會在字尾加上'\r\n'
      digitalWrite(LED_Control,1);
      Serial.println("Led On");
    }
    if(Word == "Off\r\n"){
      digitalWrite(LED_Control,0);
      Serial.println("Led Off");
    }
    BT.println(Word);  
    Serial.print(Word);
  }
}
