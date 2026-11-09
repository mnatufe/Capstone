//Version 1.0.0
#include "setup.h"
#include <Arduino.h>
#include "Wire.h"

//Generate random number between 0 and 100 to send over i2c
void onRequest() {
  uint32_t randomNumber = random(0, 100);
  Wire.print(randomNumber);
  Serial.println("onRequest");
  Serial.println();
}

void onReceive(int len) {
  Serial.printf("onReceive[%d]: ", len);
  while (Wire.available()) {
    Serial.write(Wire.read());
  }
  Serial.println();
}

