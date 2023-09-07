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
    void read(int pin);
    int humidity;
    int temperature;
};

#endif
