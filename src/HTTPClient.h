#ifndef HTTPClient_h
#define HTTPClient_h

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

class HTTPClient
{
public:
    HTTPClient(const char *fullUrl);
    int connectWiFi(const char *ssid, const char *password);
    int postSingleSensor(int teamId, const String &sensor1Name, const String &sensor1Value);
    int postDoubleSensor(int teamId, const String &sensor1Name, const String &sensor1Value, const String &sensor2Name, const String &sensor2Value);
    String getRequest();

private:
    const char *_fullUrl;
};

#endif
