#include <Wire.h>

#define ARDUINO_ADDRESS 9 // Change this to the address of your Arduino (Nucleo-64) slave

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  String messageFromTTGO = "Hello, Arduino!"; // Message to be sent from TTGO

  // Send data from TTGO to Arduino
  Wire.beginTransmission(ARDUINO_ADDRESS);
  Wire.write((const uint8_t*)messageFromTTGO.c_str(), messageFromTTGO.length());
  byte error1 = Wire.endTransmission();

  if (error1 == 0) {
    Serial.println("TTGO to Arduino: Message sent!");
  } else {
    Serial.println("TTGO to Arduino: Transmission error!");
  }

  // Receive data from Arduino
  Wire.requestFrom(ARDUINO_ADDRESS, 32); // Request data from Arduino
  while (Wire.available()) {
    char receivedChar = Wire.read();
    Serial.print("Received from Arduino: ");
    Serial.println(receivedChar);
  }

  delay(1000);
}
