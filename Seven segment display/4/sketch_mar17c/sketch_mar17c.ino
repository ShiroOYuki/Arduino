int com[4]={10,11,12,13};
int LED[8] = {2,3,4,5,6,7,8,9};
int num[4] = {0xc0,0xf8,0xf9,0xb0};
int i,j,k;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(i = 0;i<4;i++){
    pinMode(com[i],OUTPUT);
  }
  for(i = 0;i<8;i++){
    pinMode(LED[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=3;i>=0;i--){
    digitalWrite(com[i],HIGH);
    delay(100);
      for(k=0;k<8;k++){
        Serial.print(bitRead(num[j],k));
        Serial.println();
        if(bitRead(num[i],k)==0){
          digitalWrite(LED[k],LOW);
        }
        else{
          digitalWrite(LED[k],HIGH);
        }
      
    }
    
   
    
    digitalWrite(com[i],LOW);
  }
  }
