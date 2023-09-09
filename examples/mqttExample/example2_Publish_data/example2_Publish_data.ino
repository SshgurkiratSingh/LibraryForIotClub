#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <PubSubClientTools.h>

#define WIFI_SSID "Wifi name "
#define WIFI_PASS "password"
#define MQTT_SERVER "192.168.1.100"

WiFiClient espClient;
PubSubClient client(MQTT_SERVER, 1883, espClient);
PubSubClientTools mqtt(client);


int value = 0;
const String s="";

void setup() {
  randomSeed(analogRead(A0));
  Serial.begin(115200);
  Serial.println();

  // Connect to WiFi
  Serial.print(s+"Connecting to WiFi: "+WIFI_SSID+" ");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("connected");

  // Connect to MQTT
  Serial.print(s+"Connecting to MQTT: "+MQTT_SERVER+" ... ");
  if (client.connect("ESP8266Client")) {
    Serial.println("connected");

  
  } else {
    Serial.println(s+"failed, rc="+client.state());
  }

}

void loop() {
  delay(5000);
  value =random(1024);
  publisher();
}

void publisher() {
 
  mqtt.publish("t1/random", String(value));
}
