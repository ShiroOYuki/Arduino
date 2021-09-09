int LED[2][4] = {{2, 3, 4, 5}, {6, 7, 8, 9}};

void setup() {
  pinMode(LED[0][0], OUTPUT);
  pinMode(LED[0][1], OUTPUT);
  pinMode(LED[0][2], OUTPUT);
  pinMode(LED[0][3], OUTPUT);
  pinMode(LED[1][0], OUTPUT);
  pinMode(LED[1][1], OUTPUT);
  pinMode(LED[1][2], OUTPUT);
  pinMode(LED[1][3], OUTPUT);
}

void loop() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(LED[i][0], HIGH);
    digitalWrite(LED[i][1], HIGH);
    digitalWrite(LED[i][2], HIGH);
    digitalWrite(LED[i][3], HIGH);
    delay(500);
    digitalWrite(LED[i][0], LOW);
    digitalWrite(LED[i][1], LOW);
    digitalWrite(LED[i][2], LOW);
    digitalWrite(LED[i][3], LOW);
  }
}

