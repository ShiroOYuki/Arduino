int num;
char inc;
int nowlight;
int mode;
int LED[8] = {2,3,4,5,6,7,8,9};

void setup() {
  // put your setup code here, to run once:
  for(int i =0;i<8;i++){
    pinMode(LED[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    inc = Serial.read();
    nowlight = inc-'0';
    Serial.println(nowlight);
    for(int i=0;i<8;i++){
      mode = i==nowlight?HIGH:LOW;
      digitalWrite(LED[i],mode);
    }
  }
  
}
