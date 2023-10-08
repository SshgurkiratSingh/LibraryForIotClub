#ifndef MobileCar_h
#define MobileCar_h

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

typedef void (*MessageCallback)(const String &); // Define a function pointer type for callbacks

class MobileCar
{
public:
    MobileCar(int port = 80); // Constructor with default port 80
    void startWifi(const char *ssid, const char *password);
    void setupServer(MessageCallback callback); // Pass the callback function
    void handleClient();

private:
    ESP8266WebServer server;
};

#endif
