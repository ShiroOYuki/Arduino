//IC 74595
int latchPin = 8;  // Latch pin (STCP腳位)
int clockPin = 12; // Clock pin (SHCP腳位)
int dataPin = 11;  // Data pin (DS腳位)
int data[3]={127,112};
int choose[3]={9,10};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  for(int i=0;i<2;i++){
    pinMode(choose[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  twoBit_7Segment(data,choose);
}

void twoBit_7Segment(int var[3],int choose[3]){
  for(int i=0;i<2;i++){
    
    digitalWrite(choose[i],1);
    //you can write some IC function here,
    
    IC_74595(var[i],11,8,12);
    IC_74595(0,11,8,12);
    
    //EX.
    //someFunction(var[i])
    
    digitalWrite(choose[i],0);
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
  digitalWrite(latchPin,0);
  shiftOut(dataPin, clockPin, LSBFIRST, data);
  digitalWrite(latchPin,1);
}

//01110000=128+64+32=224
