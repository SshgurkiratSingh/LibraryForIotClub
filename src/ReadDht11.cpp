#include "ReadDht11.h"
ReadDht11::ReadDht11(int pin) : _pin(pin)
{
    pinMode(_pin, INPUT);
    refresh();
}
void ReadDht11::refresh()
{
    read();
}
void ReadDht11::read()
{
    uint8_t bits[5];
    uint8_t cnt = 7;
    uint8_t idx = 0;
    for (int i = 0; i < 5; i++)
        bits[i] = 0;

    delay(200);
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    delay(18);
    digitalWrite(_pin, HIGH);
    delayMicroseconds(40);
    digitalWrite(_pin, LOW);
    pinMode(_pin, INPUT);

    unsigned int loopCnt = 10000;
    while (digitalRead(_pin) == LOW && loopCnt-- > 0)
        ;
    loopCnt = 30000;
    while (digitalRead(_pin) == HIGH && loopCnt-- > 0)
        ;

    for (int i = 0; i < 40; i++)
    {
        loopCnt = 10000;
        while (digitalRead(_pin) == LOW && loopCnt-- > 0)
            ;
        unsigned long t = micros();
        loopCnt = 10000;
        while (digitalRead(_pin) == HIGH && loopCnt-- > 0)
            ;

        if ((micros() - t) > 50)
            bits[idx] |= (1 << cnt);
        if (cnt == 0)
        {
            cnt = 7;
            idx++;
        }
        else
        {
            cnt--;
        }
    }

    humidity = bits[0];
    temperature = bits[2];
}
