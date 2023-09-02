// ESP8266 code (Sender)

int counter = 0;

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
 
  Serial.println(counter);
  
  counter++;
  
  delay(1000); // Wait for 1 second
}
