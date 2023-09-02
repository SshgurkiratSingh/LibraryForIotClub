#include "HTTPClient.h"

HTTPClient httpClient("http://server.com/full-endpoint");

void setup()
{
    Serial.begin(115200);

    int wifiStatus = httpClient.connectWiFi("your-SSID", "your-PASSWORD");

    if (wifiStatus == 0)
    {
        Serial.println("Successfully connected to WiFi.");
    }
    else
    {
        Serial.println("Failed to connect to WiFi.");
        return;
    }

    int postStatusCode1 = httpClient.postSingleSensor(1, "Temperature", "25.5");
    Serial.println("Single Sensor POST Status Code: " + String(postStatusCode1));

    int postStatusCode2 = httpClient.postDoubleSensor(1, "Temperature", "25.5", "Humidity", "60%");
    Serial.println("Double Sensor POST Status Code: " + String(postStatusCode2));

    String getData = httpClient.getRequest();
    Serial.println("GET Data: " + getData);
}

void loop()
{
    delay(10000);
}
