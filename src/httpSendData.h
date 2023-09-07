#ifndef httpSendData_h
#define httpSendData_h

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

class httpSendData
{
public:
  httpSendData(const char *fullUrl);
  int connectWiFi(const char *ssid, const char *password);
  int postSingleSensor(int teamId, const String &sensor1Name, const float sensor1Value);
  int postDoubleSensor(int teamId, const String &sensor1Name, const float sensor1Value, const String &sensor2Name, const float sensor2Value);
  String getRequest();

private:
  const char *_fullUrl;
};

#endif
