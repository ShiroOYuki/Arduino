int choose[5]={2,3,4,5};
int var[5]={0,0,0,0};

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  fourBit_7Segment(var,choose);
}

void fourBit_7Segment(int[] var,int choose[5]){
  for(int i=0;i<4;i++){
    pinMode(choose,OUTPUT);
  }
  for(int i=0;i<4;i++){
    digitalWrite(choose[i],1);
    //you can write some IC function here,
    //value=var[i]
    
    //EX.
    //someFunction(var[i])
    
    digitalWrite(choose[i],0);
  }
}

