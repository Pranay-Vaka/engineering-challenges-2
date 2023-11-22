#include <Wire.h>

void setup() {
  Wire.begin(8);                // Address of the Arduino is 8
  Wire.onReceive(receiveEvent); // Callback function for receiving data
  Serial.begin(115200);         // Initialize Serial communication for debugging
}

void loop() {
  delay(100); // Allow for some delay in the loop
}

void receiveEvent(int bytes) {
  while (Wire.available()) { // While data is available to read
    char c = Wire.read();    // Read the received byte
    Serial.print(c);          // Print the received byte
  }
}
