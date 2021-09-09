#define MAX_INPUT 90

char inputary[MAX_INPUT+1];

void setup() 
{
  Serial.begin(9600);
  inputary[0] = '\0';
  Serial.println("Begin:");
}

void loop() {
  if (Serial.available()>0)
  {
    char input = Serial.read();
    static int s_len;
    if (s_len>=MAX_INPUT) {
    //nothing
    } 
    else if (input != '\n' && input != '\r') {
      inputary[s_len++] = input;
    } 
    else {
      Serial.print("RECEIVED MSG: ");
      Serial.println(inputary);
      for(int i=0;i<90;i++){
        if(inputary[i]=='A'&&inputary[i+1]=='B'){
          i+=1;
          Serial.print("87");
          continue;  
        }
        else if(inputary[i]=='A'){
          Serial.print("0");
        }
        else if(inputary[i]=='B'){
          Serial.print("1");
        }
        
      }
      Serial.println();
      memset(inputary, 0, sizeof(inputary));
      s_len = 0;        
    }
  }
}
