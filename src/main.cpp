#include <Arduino.h>
#include <SoftwareSerial.h>
#include <stdlib.h>
#include "ESP8266.h"

Core::ESP8266 esp(2, 3);

void setup() {
  Serial.begin(115200);
  esp.begin(115200);

  esp.send("AT");
  delay(1000);
}

void loop() {
  while (esp.hasData()) {
    String data = esp.read();
    Serial.println(data);
  }

  delay(1000);
}