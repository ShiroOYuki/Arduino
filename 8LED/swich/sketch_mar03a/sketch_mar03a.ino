int LED[8]={9,8,7,6,5,4,3,2};
int i;
int j=0;
int sw=13;
long t20;
int f=0;
void setup(){
    for(i=0;i<9;i++){
      pinMode(LED[i],OUTPUT);
    }
      pinMode(sw,INPUT);
}

void loop(){
  if((millis()-t20)>20)
  {
    t20=millis();
    if(sw!= digitalRead(13))
    {
      sw=digitalRead(13);
      if(sw==0)
      {
        f++;
        f=f % 2;     
      }      
    }
  } 
  if(f==0)
  {
    for(i=j;i<9;i++)
    {
      j=i;
      if(j>=8){
        j=0;
        i=j;
      }
      digitalWrite(LED[i],HIGH);
      delay(500);
      digitalWrite(LED[i],LOW);
      if(sw!= digitalRead(13))
      {
        sw=digitalRead(13);
        if(sw==0)
        {
          f++;
          f=f % 2;     
        }      
      }
      if(f == 0){
        break;
      }
    }
  }
}
