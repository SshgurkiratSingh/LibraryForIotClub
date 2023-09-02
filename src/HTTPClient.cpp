#include "HTTPClient.h"
#include <ArduinoJson.h>

HTTPClient::HTTPClient(const char *fullUrl)
{
    _fullUrl = fullUrl;
}

int HTTPClient::connectWiFi(const char *ssid, const char *password)
{
    WiFi.begin(ssid, password);
    unsigned long startTime = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        if (millis() - startTime > 8000)
        {
            return -1;
        }
        delay(250);
    }

    return 0;
}

int HTTPClient::postSingleSensor(int teamId, const String &sensor1Name, const String &sensor1Value)
{
    HTTPClient http;

    http.begin(_fullUrl);
    http.addHeader("Content-Type", "application/json");

    DynamicJsonDocument doc(256);
    doc["teamId"] = teamId;
    doc["sensor1Name"] = sensor1Name;
    doc["sensor1Value"] = sensor1Value;

    String payload;
    serializeJson(doc, payload);

    int httpCode = http.POST(payload);
    http.end();

    return httpCode;
}

int HTTPClient::postDoubleSensor(int teamId, const String &sensor1Name, const String &sensor1Value, const String &sensor2Name, const String &sensor2Value)
{
    HTTPClient http;

    http.begin(_fullUrl);
    http.addHeader("Content-Type", "application/json");

    DynamicJsonDocument doc(512);
    doc["teamId"] = teamId;
    doc["sensor1Name"] = sensor1Name;
    doc["sensor1Value"] = sensor1Value;
    doc["sensor2Name"] = sensor2Name;
    doc["sensor2Value"] = sensor2Value;

    String payload;
    serializeJson(doc, payload);

    int httpCode = http.POST(payload);
    http.end();

    return httpCode;
}

String HTTPClient::getRequest()
{
    HTTPClient http;

    http.begin(_fullUrl);

    int httpCode = http.GET();

    String response = "";
    if (httpCode > 0)
    {
        response = http.getString();
    }

    http.end();

    return response;
}
