#include <string.h>
#include "WString.h"
#include "HardwareSerial.h"
#include "functions.h"
#include <Arduino.h>
#include <util/delay.h>
#include "sensors.h"

myFunctions::myFunctions() {
}
String* myFunctions::splitCommand(String command) {
  int command_length = command.length() + 1;
  char command_array[command_length];
  command.toCharArray(command_array, command_length);
  char* data = strtok(command_array, " ");
  char** tokens = new char*[10];
  int i = 0;
  while (data != NULL) {
    tokens[i] = data;
    i++;
    data = strtok(NULL, " ");
  }
  String* result = new String[i];
  for (int j = 0; j < i; j++) {
    result[j] = String(tokens[j]);
  }
  delete[] tokens;
  return result;
}

void myFunctions::setBaudRate(int baud) {
  //Serial.begin(baud);
  Serial.print("function called");
  Serial.println(baud);
}

// void myFunctions::configSensor(String sensorName, int pinNumber, String mode) {
//   if (mode.equals("output")) {
//     pinMode(pinNumber, OUTPUT);
//     Serial.print("Pin configured to output");
//   }
//   if (mode.equals("input")) {
//     pinMode(pinNumber, INPUT);
//     Serial.print("Pin configured to input");
//   }
//   if (mode.equals("input_pullup")) {
//     pinMode(pinNumber, INPUT_PULLUP);
//     Serial.print("Set pull-up on pin");
//   }
// }
void myFunctions::configSensor(int pinNumber, String mode) {
  if (mode.equals("output")) {
    pinMode(pinNumber, OUTPUT);

  } else if (mode.equals("input")) {
    pinMode(pinNumber, INPUT);
    // Serial.print("OK configSensor input");
  } else if (mode.equals("input_pullup")) {
    pinMode(pinNumber, INPUT_PULLUP);
    //Serial.print("OK configSensor pullup");
  } else {
    Serial.print("ERR ");
    Serial.print("configSensor");
    Serial.println(" unknown mode");
  }
  Serial.print("OK ");
  Serial.print("configSensor ");
  Serial.println(mode);
}
String* myFunctions::readDigitalSensor(String sensorName, int pin) {
  bool reading = false;
  String command;
  if (sensorName.equals("HW_507")) {
    //while (!reading) {
    HW_507(pin);
    // if (Serial.available() > 0) {
    //   command = Serial.readStringUntil("\n");
    //   reading = true;
    // }
    //}
  }
  if (sensorName.equals("HW_498")) {
    while (!reading) {
      HW_498(pin);
      if (Serial.available() > 0) {
        command = Serial.readStringUntil("\n");
        reading = true;
      }
    }
  }
  String* result = new String[1];
  result[0] = command;
  return result;
}