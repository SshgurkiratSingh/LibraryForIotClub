#ifndef READDHT11_h
#define READDHT11_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class ReadDht11
{
public:
    ReadDht11(int pin);
    void refresh();
    int humidity;
    int temperature;

private:
    int _pin;
    void read();
};

#endif
