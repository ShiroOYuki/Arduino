int LED[8];

void setup() {
   for(int i=0;i<9;i++){
    LED[i]=9-i;
    pinMode(LED[i],OUTPUT);
  }
}

void loop() {
  for (int i=0;i<9;i++){
    digitalWrite(LED[i],HIGH);
    delay(500);
    digitalWrite(LED[i],LOW);
  }
}
