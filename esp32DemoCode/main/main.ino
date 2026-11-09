//Version 1.0.1
#include "setup.h"
#include "Wire.h"
#include <Arduino.h>

#define I2C_DEV_ADDR 0x48

void setup() {
  Serial.begin(115200);
  Wire.onRequest(onRequest);
  Wire.onReceive(onReceive);
  Wire.begin(I2C_DEV_ADDR);

  Serial.println("I2C Slave Initialized");
}

void loop() {
  delay(10); //delay to allow for I2C communication
}