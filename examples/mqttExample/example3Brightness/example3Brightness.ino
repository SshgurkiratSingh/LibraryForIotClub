#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <PubSubClientTools.h>
#include <stdlib.h>
#define WIFI_SSID "  "
#define WIFI_PASS "   "
#define MQTT_SERVER "192.168.1.100"

WiFiClient espClient;
PubSubClient client(MQTT_SERVER, 1883, espClient);
PubSubClientTools mqtt(client);

const String s = "";

void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(D0,OUTPUT);
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

    mqtt.subscribe("t1/test/ledBrightness",led_brightness);
  
  } else {
    Serial.println(s+"failed, rc="+client.state());
  }
digitalWrite(D0,LOW);

}

void loop() {
  client.loop();
 
}


void led_brightness(String topic, String message) {
  Serial.println(s+"Message arrived in function 1 ["+topic+"] "+message);
uint8 b=message.toInt();
analogWrite(D0,b);
}
