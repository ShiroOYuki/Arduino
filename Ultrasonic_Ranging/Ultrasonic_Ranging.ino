int trig = 11;
int echo = 12;
float distance,receiveTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);

  distance = getDistance();

  Serial.println(distance);

  
}

float getDistance(){
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);
  
  receiveTime = pulseIn(echo,1);

  distance = (receiveTime/2)/29.1;

  return distance;
}
