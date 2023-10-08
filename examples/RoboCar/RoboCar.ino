#include <MobileCar.h>

// WiFi credentials
const char *ssid = "esp_car";
const char *password = "password";

// Create Motor Configuration
#define MotorPin1 D5
#define MotorPin2 D6
#define MotorPin3 D7
#define MotorPin4 D8

// Led Config
#define LedPin D2
bool currentLedState = LOW;
// Create a MobileCar instance
MobileCar car(D0, D1);

void messageReceivedCallback(const String &msg)
{
    Serial.println("Received message: " + msg);
    if (State == "F")
    {
        digitalWrite(MotorPin1, HIGH);
        digitalWrite(MotorPin2, LOW);
        digitalWrite(MotorPin3, HIGH);
        digitalWrite(MotorPin4, LOW);
    }
    else if (State == "B")
    {
        digitalWrite(MotorPin1, LOW);
        digitalWrite(MotorPin2, HIGH);
        digitalWrite(MotorPin3, LOW);
        digitalWrite(MotorPin4, HIGH);
    }
    else if (State == "L")
    {
        digitalWrite(MotorPin1, LOW);
        digitalWrite(MotorPin2, HIGH);
        digitalWrite(MotorPin3, HIGH);
        digitalWrite(MotorPin4, LOW);
    }
    else if (State == "R")
    {
        digitalWrite(MotorPin1, HIGH);
        digitalWrite(MotorPin2, LOW);
        digitalWrite(MotorPin3, LOW);
        digitalWrite(MotorPin4, HIGH);
    }
    else if (State == "S")
    {
        digitalWrite(MotorPin1, LOW);
        digitalWrite(MotorPin2, LOW);
        digitalWrite(MotorPin3, LOW);
        digitalWrite(MotorPin4, LOW);
    }
    else if (State == "H")
    {
        currentLedState = !currentLedState;
        digitalWrite(LedPin, currentLedState);
    }
}

void setup()
{
    // Initialize WiFi and web server
    car.startWifi(ssid, password);

    // Initialize Ultrasonic sensor
    car.setupUltraSonic(D3, D4);

    // Initialize the motor pins
    pinMode(MotorPin1, OUTPUT);
    pinMode(MotorPin2, OUTPUT);
    pinMode(MotorPin3, OUTPUT);
    pinMode(MotorPin4, OUTPUT);
    digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, LOW);
    digitalWrite(MotorPin3, LOW);
    digitalWrite(MotorPin4, LOW);
    // Set up the web server and register a callback for messages
    car.setupServer(messageReceivedCallback);
}

void loop()
{
    // Keep the server running
    car.handleClient();
}
