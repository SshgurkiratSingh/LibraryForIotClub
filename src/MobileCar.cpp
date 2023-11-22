#include "MobileCar.h"

MobileCar::MobileCar(int irPin1, int irPin2 ,int port) : server(port)
{
    irPins[0] = irPin1;
    irPins[1] = irPin2;
    
}

void MobileCar::startWifi(const char *ssid, const char *password)
{

    Serial.begin(115200);
    Serial.println("AP MODE...");
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
}

void MobileCar::setupServer(MessageCallback callback, const char *endPoint)

{
    server.on(String(endPoint), HTTP_GET, [this, callback]()
              {
        DynamicJsonDocument doc(256);
        for (int i = 0; i < maxIRSensor; i++) {
            int sensorValue = digitalRead(irPins[i]);
            doc[String("ir" + String(i + 1))] = sensorValue;
        }
#if ULTRASONICENABLED
        digitalWrite(_trigg, LOW);
        delayMicroseconds(2);
        digitalWrite(_trigg, HIGH);
        delayMicroseconds(10);
        digitalWrite(_trigg, LOW);
        int duration = pulseIn(_echo, HIGH);
        float distance = duration * 0.0344 / 2;
        doc["fc"] = distance;
#endif
        if (server.hasArg("State")) {
            String msg = server.arg("State");
            callback(msg);
        }

        String json;
        serializeJson(doc, json);
        server.send(200, "application/json", json); });

    server.begin();
}
void MobileCar::setupUltraSonic(int trigg, int echo)
{
    _trigg = trigg;
    _echo = echo;
    pinMode(_trigg, OUTPUT);
    pinMode(_echo, INPUT);
}

void MobileCar::handleClient()
{
    server.handleClient();
}
