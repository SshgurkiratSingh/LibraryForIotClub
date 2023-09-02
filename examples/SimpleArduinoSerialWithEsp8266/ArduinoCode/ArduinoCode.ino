// Arduino code (Receiver)
#include <SoftwareSerial.h>

SoftwareSerial esp8266Serial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600); // Initialize serial communication
  esp8266Serial.begin(9600);
}

void loop() {

    String incomingData = esp8266Serial.readStringUntil('\n'); // Read the incoming data until a newline character is received
    Serial.print("Received: ");
    Serial.println(incomingData);

}
