const int PIR=8;
const int LED_R=9;
const int LED_G=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIR,INPUT);
  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  for(int i = 0;i<5;i++){
    // PIR 校正5秒
    Serial.println(i);
    delay(1000);  
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  int isMoving = digitalRead(PIR);
  int v = analogRead(PIR);
  Serial.print("isMoving:");
  Serial.print(isMoving);
  Serial.print("\tv:");
  Serial.println(v);
  if(isMoving==0){
    digitalWrite(LED_R,1);
    digitalWrite(LED_G,0);
  }
  else{
    digitalWrite(LED_R,0);
    digitalWrite(LED_G,1);
  }
    
}
