#include <Arduino.h>
#include <SoftwareSerial.h>
#include <stdlib.h>

#include "ESP8266.h"
#include "AM312.h"

Core::AM312 motionSensor(2);
int redLEDPin = 12;
int greenLEDPin = 13;

void motionInterrupt() {
  int input = motionSensor.read();

  if (input == HIGH) {
    Serial.println("I SEE YOU >:)");
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
  } else {
    Serial.println("0 Motion :(");
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
  }
}

void setup() {
  Serial.begin(9600);

  motionSensor.begin();
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(motionSensor.getPin()), motionInterrupt, CHANGE);
}

void loop() { }