//IC 74595
int latchPin = 8;  // Latch pin (STCP腳位)
int clockPin = 12; // Clock pin (SHCP腳位)
int dataPin = 11;  // Data pin (DS腳位)
int data[3]={112,127};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  IC_74595(data,11,8,12);
}

void IC_74595(int data[3],int dataPin,int latchPin,int clockPin){
  /*
   * Q0:IC Pin 15
   * Q1~Q7:IC Pin 1~7
   * ~MR:IC Pin 10 -> VCC
   * SHCP(Clock pin):IC Pin 11
   * STCP(Latch Pin):IC Pin 12
   * ~OE:IC Pin 13 -> GND
   * Data:IC Pin 14
   */
   digitalWrite(latchPin,0);
   shiftOut(dataPin, clockPin, LSBFIRST, data[0]);
   shiftOut(dataPin, clockPin, LSBFIRST, data[1]);
   digitalWrite(latchPin,1);
}
