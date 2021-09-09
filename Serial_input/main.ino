char inputary[5];

void setup(){
    Serial.begin(9600);
    inputary[0] = '\0';
}

void loop(){
  if(Serial.available() > 0){
    char input = Serial.read();
    static int input_len;
    if (input_len < 5){

    }
    else if(input != '\n' && input != '\r'){
        inputary[input_len++] = input;
    }
    else{
        Serial.println(inputary);
        input_len = 0;
    }
      
      
  }  
  
}