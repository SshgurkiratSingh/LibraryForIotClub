#include "MobileCar.h"

MobileCar::MobileCar(int irPin1, int irPin2, int irPin3, int irPin4, int port) : server(port)
{
    irPins[0] = irPin1;
    irPins[1] = irPin2;
    irPins[2] = irPin3;
    irPins[3] = irPin4;
}

void MobileCar::startWifi(const char *ssid, const char *password)
{

    Serial.begin(115200);
    Serial.println("AP MODE...");
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
}

void MobileCar::setupServer(MessageCallback callback, endpoint)
{
    _endpoint = endpoint;
    server.on(String(endpoint), HTTP_GET, [this, callback]()
              {
        DynamicJsonDocument doc(256);
        for (int i = 0; i < maxIRSensor; i++) {
            int sensorValue = analogRead(irPins[i]);
            doc[String("ir" + String(i + 1))] = sensorValue;
        }

        if (server.hasArg("msg")) {
            String msg = server.arg("msg");
            callback(msg);
        }

        String json;
        serializeJson(doc, json);
        server.send(200, "application/json", json); });

    server.begin();
}

void MobileCar::handleClient()
{
    server.handleClient();
}
