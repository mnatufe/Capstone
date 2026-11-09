//Version 1.0.0
#include setup.h

#define I2C_DEV_ADDR 0x48

void setup() {
  Serial.begin(115200);
  Wire.onRequest(onRequest);
  Wire.onReceive(onReceive);
  Serial.println("I2C Slave Initialized");
  Wire.begin(I2C_DEV_ADDR);
}

void loop() {
  delay(10); //delay to allow for I2C communication
}