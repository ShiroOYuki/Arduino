int LED[9]={2,4,6,8,9,7,5,3,2};

void setup() {
   for(int i=0;i<10;i++){
    pinMode(LED[i],OUTPUT);
  }
}

void loop() {
  for (int i=0;i<10;i++){
    digitalWrite(LED[i],HIGH);
    delay(500);
    digitalWrite(LED[i],LOW);
  }
}
