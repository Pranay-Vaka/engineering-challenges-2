#include <Wire.h>

#define TTGO_ADDRESS 8 // Address of the TTGO ESP32 slave

char receivedString[32] = "Hello, TTGO!"; // Initial message to be sent from Arduino

void setup() {
  Wire.begin(TTGO_ADDRESS); // Set up I2C communication with the specified address
  Wire.onRequest(sendData); // Function to handle data requests
  Serial.begin(9600);
}

void loop() {
  // Receive data from TTGO
  Wire.requestFrom(TTGO_ADDRESS, 32); // Request data from TTGO
  while (Wire.available()) {
    char receivedChar = Wire.read();
    Serial.print("Received from TTGO: ");
    Serial.println(receivedChar);
  }

  delay(1000);
}

void sendData() {
  Wire.write((const uint8_t*)receivedString, strlen(receivedString)); // Send data to TTGO
}
