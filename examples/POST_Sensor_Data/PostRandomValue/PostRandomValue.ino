#include <httpSendData.h>
// Enter the url which is given by Coordinating Team
httpSendData sendData("http://192.168.1.100:3000/api/post/sensor");
void setup()
{
    // Setting Seeds for random value
    randomSeed(analogRead(0));
    Serial.begin(9600);
    // Connecting·to·WiFi
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