int state = 0;
int i = 0;
int j;
int F=1;
int LED[8] = {2,3,4,5,6,7,8,9};
int sw = 13;
long t500;
long t20;
int num[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};


void setup() {
  // put your setup code here, to run once:
  for(i=0;i<8;i++){
    pinMode(LED[i],OUTPUT);
  }
  pinMode(sw,INPUT);
}

void loop() {
  if((millis()-t20)>20)
  {
    t20=millis();
    if(sw!= digitalRead(13))
    {
      sw=digitalRead(13);
      if(sw==0)
      {
        F++;
        F=F % 2;     
      }      
    }
  }
  if(F==1){
    if((millis()-t500)>500){
      t500 = millis();
      state = ~state;
      for(j=0;j<8;j++){
        if(bitRead(num[i],j)==0){
          digitalWrite(LED[j],LOW);
        }
        else{
          digitalWrite(LED[j],HIGH);
        }
     }
     i++;
     if(i>9){
       i=0;
     }
    }
  }
}
