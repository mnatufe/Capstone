//Version 1.0.0
#include "setup.h"
#include <Arduino.h>
#include "Wire.h"

uint32_t i = 0;
uint32_t randomNumber = random(0, 100);


//Generate random number between 20 and 35 to send over i2c
void onRequest() {
  float temperature = random(2000, 3501) / 100.0f;
    int16_t raw = (int16_t)(temperature / 0.0625f);
    uint16_t encoded = (uint16_t)raw << 4;

    uint8_t data[2] = {
        (uint8_t)(encoded >> 8),
        (uint8_t)(encoded & 0xFF)
    };

    Wire.write(data, 2);
}

void onReceive(int len) {
  Serial.printf("onReceive[%d]: ", len);
  while (Wire.available()) {
    Serial.write(Wire.read());
  }
  Serial.println();
}

