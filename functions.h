#include "WString.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class myFunctions {
public:
  myFunctions();
  String* splitCommand(String command);
  void setBaudRate(int baud);
  //void configSensor(String sensorName, int pinNumber, String mode);
  void configSensor(int pinNumber, String mode);
  String* readDigitalSensor(String sensorName, int pin);
};

#endif