# Arduino and ESP8266 Serial Communication using SoftwareSerial

This repository contains sample Arduino and ESP8266 code for establishing serial communication between the two devices using SoftwareSerial library. The Arduino acts as the receiver and the ESP8266 as the sender, incrementing a counter and sending it to the Arduino for display.

## Prerequisites

- Arduino IDE installed on your computer.
- Basic knowledge of Arduino programming.
- An Arduino board and an ESP8266 module.
- Jumper wires to connect the Arduino and ESP8266.

## Installation

1. Connect the Arduino and ESP8266 as described in the code comments or your specific setup.
2. Open the Arduino IDE and upload the provided Arduino (Receiver) code to your Arduino board.
3. Open the Arduino IDE and upload the provided ESP8266 (Sender) code to your ESP8266 module.

## Usage

1. Open the Serial Monitor in the Arduino IDE for both the Arduino and ESP8266.
2. Select the correct COM port and set the baud rate to 9600 for each Serial Monitor.
3. The Arduino (Receiver) will display the data received from the ESP8266 (Sender) in the Serial Monitor.

## Code Explanation

- The Arduino code (`Receiver`) initializes a SoftwareSerial object to communicate with the ESP8266.
- The ESP8266 code (`Sender`) also initializes a SoftwareSerial object to communicate with the Arduino.
- The ESP8266 sends a counter value to the Arduino every 1 second.
- The Arduino reads the data from the ESP8266 and displays it in the Serial Monitor.

## Resistor Network

- Use 3 1k resistor to form voltage divider network between Arduino 5V and ground.
- The resistor next to 5v will be connected to ESP8266 RX pin.
