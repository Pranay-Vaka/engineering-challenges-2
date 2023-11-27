#include <Wire.h>

#define NUCLEO_ADDRESS 9 // Change this to the address of your Nucleo-64 (Arduino) slave

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  String message = "lmao"; // Message to be sent

  Wire.beginTransmission(NUCLEO_ADDRESS);
  Wire.write((const uint8_t*)message.c_str(), message.length()); // Cast and send the string as bytes
  byte error = Wire.endTransmission();

  if (error == 0) {
    Serial.println("Nucleo is connected!");
  } else {
    Serial.println("Nucleo is not connected!");
  }

  delay(1000);
}


