int trig = 6;
int echo = 7;
float distance;

int Pin_A = 10;
int Pin_B = 11;
int Pin_C = 12;
int Pin_D = 13;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  //CD4511
  pinMode(Pin_A,OUTPUT);
  pinMode(Pin_B,OUTPUT);
  pinMode(Pin_C,OUTPUT);
  pinMode(Pin_D,OUTPUT);
}

void loop() {
  delay(500);

  distance = getDistance(trig,echo);

  Serial.println(distance);
  int val = (int)distance/3;
  Serial.println(val);
  IC_CD4511(val);
}

float getDistance(int trigPin,int echoPin){
  float distance,receiveTime;
  digitalWrite(trigPin,1);
  delayMicroseconds(10);
  digitalWrite(trigPin,0);
  
  receiveTime = pulseIn(echoPin,1);

  distance = (receiveTime/2)/29.1;

  return distance;
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
   * Pin 3 -> NC
   * ripple blanking:IC Pin 4 -> Vcc
   * enable/store input:IC Pin 5 -> GND
   * Vss:IC Pin 8 -> GND
   * 
   * -----If IC is 7448-----
   * Pin 3,4,5 不接
   */
  int D=0,C=0,B=0,A=0;
  if(val <=10){
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
  }
  else{
    A=1;
    B=1;
    C=1;
    D=1;  
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
