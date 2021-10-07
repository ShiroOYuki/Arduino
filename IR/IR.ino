#include <IRremote.h>

const byte IR_RECEIVE_PIN = 8;
const int Relay[4] = {9,10,11};
int val = 0;

void setup()
{
   Serial.begin(115200);
   Serial.println("IR Receive test");
   for(int i=0;i<3;i++){
      pinMode(Relay[i],OUTPUT);
   }
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
   val = 0;
   if (IrReceiver.decode())
   {
      val = IrReceiver.decodedIRData.command;
      Serial.println(val);
      control(val);
      delay(100);
      IrReceiver.resume();
   }
}

void control(int val){
  switch(val){
    case 21:{
      Serial.println("HAHA");
      break;
    }
    case 74:{
      Serial.println("Relay");
      digitalWrite(9,0);
      break;
    }
    case 82:{
      Serial.println("Relay");
      digitalWrite(10,0);
      break;
    }
    case 66:{
      Serial.println("Relay");
      digitalWrite(11,0);
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
