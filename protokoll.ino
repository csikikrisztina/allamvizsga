#include "functions.h"
String strLine;
myFunctions f;
void setup() {
  Serial.begin(9600);
}

String ReadLine(void)
{
 // strLine="";
  if (Serial.available() > 0) {
      strLine = Serial.readStringUntil("\n");
      return strLine;
    }
    return "";
}

void ParseLine(String strline)
{
  strline.setCharAt(strline.length()-1,0);
  String* tokens = f.splitCommand(strline);

  String functionName = String(tokens[0]);
  String sensorName;
  // Serial.print("Token ");
  // Serial.println(functionName);
  String trimmedFunctionName = functionName;
  trimmedFunctionName.trim();
  if (trimmedFunctionName.equals("readSensor")) {
    sensorName = String(tokens[1]);
    int pin = atoi(tokens[2].c_str());
    bool reading = true;
    String* sensorData = f.readDigitalSensor(sensorName, pin);
    strLine = sensorData[0];
    
  }
  else if (trimmedFunctionName.equals("setBaudRate")) {
    int baud = atoi(tokens[1].c_str());
    f.setBaudRate(baud);
  }
  else if (trimmedFunctionName.equals("configSensor")) {
    //String sensorName = String(tokens[1]);
    int pin = atoi(tokens[1].c_str());
    String mode = String(tokens[2]);
    String trimmedMode = mode;
    trimmedMode.trim();
    f.configSensor(pin, trimmedMode);
  }
  else {
      Serial.print("ERR ");Serial.print(functionName);Serial.println(" unknown command");
  }
}

void loop() {

  strLine=ReadLine();
  if (strLine!="")
    ParseLine(strLine);
  
  delay(1);
}