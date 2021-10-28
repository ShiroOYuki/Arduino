#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  digitalWrite(9,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String inp = Serial.readString();
    String mode;
    char data[30];
    
    mode = getValue(inp,' ',0);
    getValue(inp,' ',1).toCharArray(data,30);
    
    Serial.print("Mode:");
    Serial.println(mode);
    Serial.print("Data:");
    Serial.println(data);

    if(mode=="r"){
      char EEPROMData[30];
      EEPROM.get(0,EEPROMData);
      Serial.print("Get:");
      Serial.println(EEPROMData);
    }
    else if(mode=="w"){
      Serial.print("Write:");
      Serial.println(data);
      EEPROM.put(0,data);
    }
    delay(100);
  }
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
