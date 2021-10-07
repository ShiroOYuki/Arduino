float distance;
int trig = 10;
int echo = 8;
int num;

int latchPin = 7;  // Latch pin (STCP腳位)
int clockPin = 6; // Clock pin (SHCP腳位)
int dataPin = 4;  // Data pin (DS腳位)

int choose[5]={11,12,13,14};
int dp = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dp, OUTPUT);
  for(int i=0;i<4;i++){
    pinMode(choose[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(500);

  distance = getDistance(trig,echo);
  Serial.println(distance);


  for(int i=0;i<4;i++){
      digitalWrite(choose[i],1);
      num=distance/(1*pow(10,2-i));
      distance-=num*(1*pow(10,2-i));
      Serial.println(num);
      digitalWrite(latchPin,0); //送資料前要先把 latchPin 設成低電位
      shiftOut(dataPin, clockPin, LSBFIRST, num); //送出資料，例如輸入170，就是2進位的10101010 -> 8顆LED燈會照這樣亮
      digitalWrite(latchPin,1); // 送完資料後要把 latchPin 設成高電位
      
      if(i<3){
        digitalWrite(dp,0);
      }
      else{
        digitalWrite(dp,1);
      }
      digitalWrite(choose[i],0);
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

void IC_74595(int data,int dataPin,int latchPin,int clockPin){
  /*
   * Q0:IC Pin 15
   * Q1~Q7:IC Pin 1~7
   * ~MR:IC Pin 10 -> VCC
   * SHCP(Clock pin):IC Pin 11
   * STCP(Latch Pin):IC Pin 12
   * ~OE:IC Pin 13 -> GND
   * Data:IC Pin 14
   */
}
