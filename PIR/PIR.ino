const int PIR=8;
const int LED_R=9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIR,INPUT);
  pinMode(LED_R,OUTPUT);
  for(int i = 0;i<5;i++){
    // PIR 校正10秒
    Serial.println(" ");
    delay(1000);  
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  int isAnyMove = digitalRead(PIR);
  int v = analogRead(PIR);
  Serial.print("isAnyMove:");
  Serial.print(isAnyMove);
  Serial.print("\tv:");
  Serial.println(v);
  if(isAnyMove==0)
    digitalWrite(LED_R,1);
  else
    digitalWrite(LED_R,0);
}
