#include <ReadDht11.h> // Including library

ReadDht11 dhtSensor(D4); // Initialize with pin D4 on NodeMCU

void setup()
{
    Serial.begin(9600);
    Serial.println("DHT11 Read Example for NodeMCU");
}

void loop()
{
    dhtSensor.refresh(); // Refresh sensor readings

// ----------------------Setting variables  --------------------------------//
    int humidity = dhtSensor.humidity; 
    int temperature = dhtSensor.temperature;

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    delay(2000); // Wait for 2 seconds before reading again
}
