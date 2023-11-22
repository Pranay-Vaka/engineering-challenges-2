#include <Wire.h>

void setup() {
  Wire.begin(); // Initialize I2C bus
  Serial.begin(115200); // Initialize Serial communication for debugging
}

void loop() {
  Wire.beginTransmission(8); // Address of the slave device (Arduino) is 8
                                                     Wire.write("Hello from ESP32!"); // Data to be sent
  Wire.endTransmission(); // Finish the transmission

  delay(1000); // Wait for a second before sending again
}
