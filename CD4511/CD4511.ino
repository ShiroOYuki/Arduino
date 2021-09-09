int Pin_A = 9;
int Pin_B = 10;
int Pin_C = 11;
int Pin_D = 12;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //CD4511
  pinMode(Pin_A,OUTPUT);
  pinMode(Pin_B,OUTPUT);
  pinMode(Pin_C,OUTPUT);
  pinMode(Pin_D,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    val = Serial.parseInt();
    
    Serial.println(val);
    IC_CD4511(val);
  }
}

void IC_CD4511(int val){
  /*
   * if val > 9:OFF
   * 
   * -----INPUT-----
   * Pin_A:IC Pin 7
   * Pin_B:IC Pin 1
   * Pin_C:IC Pin 2
   * Pin_D:IC Pin 6
   * 
   * -----OUTPUT-----
   * a:IC Pin 13
   * b:IC Pin 12
   * c:IC Pin 11
   * d:IC Pin 10
   * e:IC Pin 9
   * f:IC Pin 15
   * g:IC Pin 14
   * 
   * lamp test:IC Pin 3 -> Vcc
   * ripple blanking:IC Pin 4 -> Vcc
   * enable/store input:IC Pin 5 -> GND
   * 
   * -----If IC is 7448-----
   * Pin 3,4,5 不接
   */
  int D=0,C=0,B=0,A=0;
  for(int i=0;i<val;i++){
    if(A==0)
      A=1;
    else{
      A=0;
      if(B==0)
        B=1;
      else{
        B=0;
        if(C==0)
          C=1;
        else{
          C=0;
          if(D==0)
            D=1;
          else
            D=0;
        }
      }
    }
  }
  digitalWrite(Pin_A,A);
  digitalWrite(Pin_B,B);
  digitalWrite(Pin_C,C);
  digitalWrite(Pin_D,D);
  Serial.print(D);
  Serial.print(C);
  Serial.print(B);
  Serial.println(A);
}
