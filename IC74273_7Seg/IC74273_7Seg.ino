/*
  7-Segmnet with 74LS273P

  Driving 7-Segment LED common cathode with 74LS273 Latching Flip-Flop
  
  Mohammad Al-Khanfar - October 04, 2018
*/

const int aSegLED = 2;
const int bSegLED = 3;
const int cSegLED = 4;
const int dSegLED = 5;
const int eSegLED = 6;
const int fSegLED = 7;
const int gSegLED = 8;
const int pSegLED = 9;

const int clearPin = 10;
const int clockPin = 11;

int holdPinTouch = 50;
int delayBetweenDigits = 300;

void setup()
{
  pinMode (aSegLED, OUTPUT);
  pinMode (bSegLED, OUTPUT);
  pinMode (cSegLED, OUTPUT);
  pinMode (dSegLED, OUTPUT);
  pinMode (eSegLED, OUTPUT);
  pinMode (fSegLED, OUTPUT);
  pinMode (gSegLED, OUTPUT);
  pinMode (pSegLED, OUTPUT);

  pinMode (clearPin, OUTPUT);
  pinMode (clockPin, OUTPUT);
}

void loop()
{
  //  Display Digit "."
  clearDigit();
  digitalWrite (pSegLED, HIGH);
  displayDigit();

  //  Display Digit "0"
  clearDigit();
  digitalWrite (aSegLED, HIGH);
  digitalWrite (bSegLED, HIGH);
  digitalWrite (cSegLED, HIGH);
  digitalWrite (dSegLED, HIGH);
  digitalWrite (eSegLED, HIGH);
  digitalWrite (fSegLED, HIGH);
  displayDigit();

  //  Display Digit "1"
  clearDigit();
  digitalWrite (bSegLED, HIGH);
  digitalWrite (cSegLED, HIGH);
  displayDigit();

  //  Display Digit "2"
  clearDigit();
  digitalWrite (aSegLED, HIGH);
  digitalWrite (bSegLED, HIGH);
  digitalWrite (dSegLED, HIGH);
  digitalWrite (eSegLED, HIGH);
  digitalWrite (gSegLED, HIGH);
  displayDigit();

  //  Display Digit "3"
  clearDigit();
  digitalWrite (aSegLED, HIGH);
  digitalWrite (bSegLED, HIGH);
  digitalWrite (cSegLED, HIGH);
  digitalWrite (dSegLED, HIGH);
  digitalWrite (gSegLED, HIGH);
  displayDigit();

  //  Display Digit "4"
  clearDigit();
  digitalWrite (bSegLED, HIGH);
  digitalWrite (cSegLED, HIGH);
  digitalWrite (fSegLED, HIGH);
  digitalWrite (gSegLED, HIGH);
  displayDigit();

  //  Display Digit "5"
  clearDigit();
  digitalWrite (aSegLED, HIGH);
  digitalWrite (cSegLED, HIGH);
  digitalWrite (dSegLED, HIGH);
  digitalWrite (fSegLED, HIGH);
  digitalWrite (gSegLED, HIGH);
  displayDigit();

  //  Display Digit "6"
  clearDigit();
  digitalWrite (cSegLED, HIGH);
  digitalWrite (dSegLED, HIGH);
  digitalWrite (eSegLED, HIGH);
  digitalWrite (fSegLED, HIGH);
  digitalWrite (gSegLED, HIGH);
  displayDigit();

  //  Display Digit "7"
  clearDigit();
  digitalWrite (aSegLED, HIGH);
  digitalWrite (bSegLED, HIGH);
  digitalWrite (cSegLED, HIGH);
  displayDigit();

  //  Display Digit "8"
  clearDigit();
  digitalWrite (aSegLED, HIGH);
  digitalWrite (bSegLED, HIGH);
  digitalWrite (cSegLED, HIGH);
  digitalWrite (dSegLED, HIGH);
  digitalWrite (eSegLED, HIGH);
  digitalWrite (fSegLED, HIGH);
  digitalWrite (gSegLED, HIGH);
  displayDigit();

  //  Display Digit "9"
  clearDigit();
  digitalWrite (aSegLED, HIGH);
  digitalWrite (bSegLED, HIGH);
  digitalWrite (cSegLED, HIGH);
  digitalWrite (fSegLED, HIGH);
  digitalWrite (gSegLED, HIGH);
  displayDigit();
}

void clearDigit()
{
  digitalWrite (aSegLED, LOW);
  digitalWrite (bSegLED, LOW);
  digitalWrite (cSegLED, LOW);
  digitalWrite (dSegLED, LOW);
  digitalWrite (eSegLED, LOW);
  digitalWrite (fSegLED, LOW);
  digitalWrite (gSegLED, LOW);
  digitalWrite (pSegLED, LOW);

  digitalWrite (clearPin, LOW);
  delay (holdPinTouch);
  digitalWrite (clearPin, HIGH);
  delay (holdPinTouch);
}

void displayDigit()
{
  digitalWrite (clockPin, LOW);
  delay (delayBetweenDigits);
  digitalWrite (clockPin, HIGH);
  delay (delayBetweenDigits);
}
