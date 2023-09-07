#include "DHT.h"
#include "httpSendData.h"
httpSendData httpClient("http://192.168.1.100:3000/api/post/sensor");

DHT dht(2, DHT11);

void setup()
{
    Serial.begin(9600);
    dht.begin();
    int wifiStatus = httpClient.connectWiFi("Node ", "whyitellyou");
    if (wifiStatus == 0)
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

    delay(2000);

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int postStatusCode2 = httpClient.postDoubleSensor(1, "Temperature", String(t), "Humidity", String(h));
    Serial.println("Double Sensor POST Status Code: " + String(postStatusCode2));
    Serial.print(F("Humidity: "));
    Serial.print(String(h));
    Serial.print(F("%  Temperature: "));
    Serial.println(String(t));
}