#include "httpSendData.h"

// Initialize the httpSendData object with the full URL
httpSendData httpClient("http://server.com/full-endpoint");

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);

    // Connect to WiFi
    int wifiStatus = httpClient.connectWiFi("your-SSID", "your-PASSWORD");

    // Check WiFi connection status
    if (wifiStatus == 0)
    {
        Serial.println("Successfully connected to WiFi.");
    }
    else
    {
        Serial.println("Failed to connect to WiFi.");
        return;
    }

    // Make a POST request with a single sensor
    int postStatusCode1 = httpClient.postSingleSensor(1, "Temperature", "25.5");
    Serial.println("Single Sensor POST Status Code: " + String(postStatusCode1));

    // Make a POST request with two sensors
    int postStatusCode2 = httpClient.postDoubleSensor(1, "Temperature", "25.5", "Humidity", "60%");
    Serial.println("Double Sensor POST Status Code: " + String(postStatusCode2));

    // Make a GET request
    Serial.println("GET Data: " + getData);
}

void loop()
{
    delay(10000);
}
