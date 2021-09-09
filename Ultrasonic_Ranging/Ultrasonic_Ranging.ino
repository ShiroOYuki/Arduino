float distance;
int trig = 11;
int echo = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);

  distance = getDistance(11,12);

  Serial.println(distance);
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
