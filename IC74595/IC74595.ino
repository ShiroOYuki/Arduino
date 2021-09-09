//IC 74595
int latchPin = 8;  // Latch pin (STCP腳位)
int clockPin = 12; // Clock pin (SHCP腳位)
int dataPin = 11;  // Data pin (DS腳位)
int data=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  if(Serial.available()>0){
    data = Serial.parseInt();
    Serial.println(data);
    IC_74595(data);
  }
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
  digitalWrite(latchPin,0); //送資料前要先把 latchPin 設成低電位
  shiftOut(dataPin, clockPin, LSBFIRST, data); //送出資料，例如輸入170，就是2進位的10101010 -> 8顆LED燈會照這樣亮
  digitalWrite(latchPin,1); // 送完資料後要把 latchPin 設成高電位
}
