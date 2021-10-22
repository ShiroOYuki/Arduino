#include <IRremote.h> //呼叫函式庫 (需事先下載)

const int IR_RECEIVE_PIN = 8; //IR 接收腳
const int LED[4] = {9,10,11}; //LED (RGB)
int LEDFlag[4] = {1,1,1}; //LED 目前狀態 (1 or 0)
int val = 0; //IR 接收到的值

void setup()
{
   Serial.begin(9600);
   for(int i=0;i<3;i++){
      pinMode(LED[i],OUTPUT);
   }
   
   //固定格式 (初始化 IR)
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
}

void loop()
{
   val = 0;
   if (IrReceiver.decode()) // 把接收到的資料解碼
   {
      // 解碼成 10 進制
      val = IrReceiver.decodedIRData.command;
      
      Serial.println(val);
      control(val); //呼叫副程式
      delay(1000);
      
      // 釋放 IR (不然他會一直執行前一次的輸入)
      IrReceiver.resume();
   }
}

void control(int val){
  //以 switch case 來做按鈕功能比較方便
  switch(val){
    case 74:{
      Serial.println("R");
      LEDFlag[0] = 1-LEDFlag[0];
      digitalWrite(9,LEDFlag[0]);
      break;
    }
    case 82:{
      Serial.println("G");
      LEDFlag[1] = 1-LEDFlag[1];
      digitalWrite(10,LEDFlag[1]);
      break;
    }
    case 66:{
      Serial.println("B");
      LEDFlag[2] = 1-LEDFlag[2];
      digitalWrite(11,LEDFlag[2]);
      break;
    }
    default:{
      digitalWrite(9,1);
      digitalWrite(10,1);
      digitalWrite(11,1);
      break;
    }
  }
}
