#include "MobileCar.h"

// Constructor
MobileCar::MobileCar(int port) : server(port)
{
}

void MobileCar::startWifi(const char *ssid, const char *password)
{
#ifdef DEBUG_MODE
    Serial.begin(115200);
    Serial.println("AP MODE...");
#endif
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
}

void MobileCar::setupServer(MessageCallback callback)
{
    server.on("/message", HTTP_GET, [this, callback]()
              {
        if (server.hasArg("msg")) {
            String msg = server.arg("msg");
            callback(msg);  // Call the callback function
        }
        server.send(200, "text/plain", "Message received"); });

    server.begin();
}

void MobileCar::handleClient()
{
    server.handleClient();
}
