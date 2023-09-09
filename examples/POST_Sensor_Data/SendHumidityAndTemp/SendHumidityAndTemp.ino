// Including library
#include "ReadDht11.h"
#include "httpSendData.h"
httpSendData httpClient("http://192.168.1.100:3000/api/post/sensor");

ReadDht11 dhtSensor(D4);

void setup()
{
    Serial.begin(9600);
    int wifiStatus = httpClient.connectWiFi("wifi name ", "password"); // Enter Wifi Credential
    if (wifiStatus == 0)                                             // 0 mean success
    {
        Serial.println("Successfully connected to WiFi.");
    }
    else
    {
        Serial.println("Failed to connect to WiFi.");
        return;
    }
}

void loop()
{
    dhtSensor.refresh();
    int status = httpClient.postDoubleSensor(1, "Temperature", dhtSensor.temperature, "Humidity", dhtSensor.humidity);
    Serial.println(status);
    delay(5000);
}
