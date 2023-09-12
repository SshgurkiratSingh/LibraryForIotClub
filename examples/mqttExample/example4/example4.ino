#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <PubSubClientTools.h>

#define WIFI_SSID "ConForNode"
#define WIFI_PASS "12345678"
#define MQTT_SERVER "192.168.203.113"

WiFiClient wifi;
PubSubClient client(MQTT_SERVER, 1883, wifi); // Create MQTT client object where MQTT_SERVER is host and 1883 is port number and wifi is the WiFiClient object
PubSubClientTools mqtt(client);
const int pushButton = D1;
bool lastState = false;
/**
 * Toggles the state of an LED based on the received message.
 * @param topic - The topic of the received message.
 * @param message - The received message.
 */
void led_toggle(String topic, String message)
{
  // Print the received message and topic to the serial monitor
  Serial.println("Message arrived in function 1 [" + topic + "] " + message);

  // Toggle the LED based on the message value
  if (message == "0")
  {
    // Turn off the LED
    lastState = 0;
    digitalWrite(D0, LOW);
  }
  if (message == "1")
  {
    // Turn on the LED
    lastState = 1;
    digitalWrite(D0, HIGH);
  }
}

void setup()
{
  // Initialize the serial communication
  Serial.begin(9600);
  Serial.println();
  pinMode(pushButton, INPUT_PULLUP);
  // Set D0 pin as an output pin
  pinMode(D0, OUTPUT);

  // Connect to WiFi
  Serial.print("Connecting to WiFi: " + String(WIFI_SSID) + " ... ");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // Wait until WiFi is connected
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("connected");

  // Connect to MQTT
  Serial.print("Connecting to MQTT: " + String(MQTT_SERVER) + " ... ");

  // If the client is able to connect to MQTT server
  if (client.connect("ESP8266Client"))
  {
    Serial.println("connected");

    // Subscribe to the "t1/test" topic and set the callback function to "led_toggle"
    mqtt.subscribe("t1/test", led_toggle);
  }
  else
  {
    Serial.println("failed, rc=" + client.state());
  }

  // Turn off the D0 pin
  digitalWrite(D0, LOW);
}

// The loop function is the main execution loop of the program.
void loop()
{
  // Check if the push button is pressed
  if (digitalRead(pushButton) == LOW)
  {
    // Print a message to the serial monitor indicating that the button is pressed
    Serial.println("Button pressed");

    // Delay for 350 milliseconds to debounce the button
    delay(350);

    // Publish the inverse of the last state to the MQTT topic "t1/test"
    mqtt.publish("t1/test", String(!lastState));
  }

  // Allow the client object to process any pending messages or events
  client.loop();
}
