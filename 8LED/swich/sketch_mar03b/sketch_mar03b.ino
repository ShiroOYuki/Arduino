int LED[8];
int stage = 0;
int inpin = 0;

void setup(){
   for(int i=0;i<9;i++){
    LED[i]=9-i;
    pinMode(LED[i],OUTPUT);
  }
  pinMode(inpin,INPUT);
}

void loop(){
  for (int i=0;i<9;i++){
      digitalWrite(LED[i],HIGH);
      delay(500);
      digitalWrite(LED[i],LOW);
  }
}
