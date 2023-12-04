#include <Wire.h>

#define MY_ADDRESS 9 // Address of the Nucleo-64 (Arduino) slave
#define MAX_STRING_LENGTH 32 // Maximum expected string length

char receivedString[MAX_STRING_LENGTH];

void setup() {
  Wire.begin(MY_ADDRESS); // Set up I2C communication with the specified address
  Wire.onReceive(receiveEvent); // Function to handle incoming data
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

void receiveEvent(int bytesReceived) {
  int i = 0;
  while (Wire.available() > 0 && i < MAX_STRING_LENGTH - 1) {
    receivedString[i] = Wire.read(); // Read each byte of the received string
    i++;
  }
  receivedString[i] = '\0'; // Null-terminate the string
  Serial.print("Received message: ");
  Serial.println(receivedString);
}


