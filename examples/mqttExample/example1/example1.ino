#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <PubSubClientTools.h>

#define WIFI_SSID "Wifi Name "
#define WIFI_PASS "password"
#define MQTT_SERVER "192.168.1.100"

WiFiClient wifi;
PubSubClient client(MQTT_SERVER, 1883, wifi);
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

    mqtt.subscribe("t1/test",led_toggle);
  
  } else {
    Serial.println(s+"failed, rc="+client.state());
  }
digitalWrite(D0,LOW);

}

void loop() {
  client.loop();
 
}


void led_toggle(String topic, String message) {
  Serial.println(s+"Message arrived in function 1 ["+topic+"] "+message);
  if (message=="0" ){
    digitalWrite(D0,LOW);
  }
  if (message=="1"){
    digitalWrite(D0,1);
  }
}
