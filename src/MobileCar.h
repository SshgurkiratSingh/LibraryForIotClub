#ifndef MobileCar_h
#define MobileCar_h

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

#define maxIRSensor 2

typedef void (*MessageCallback)(const String &); // Define a function pointer type for callbacks

class MobileCar
{
public:
    MobileCar(int irPin1, int irPin2, int port = 80);
    void startWifi(const char *ssid, const char *password);
    void setupServer(MessageCallback callback, const char *endPoint = "/");
    void setupUltraSonic(int trigg, int echo);
    void handleClient();

private:
    ESP8266WebServer server;
    int irPins[4];
    char *endPoint;
    int _trigg;
    int _echo;
};

#endif
