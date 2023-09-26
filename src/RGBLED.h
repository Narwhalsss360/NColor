#ifndef RGBLED_h
#define RGBLED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "RGBA.h"
#include "HSV.h"
#include "ColorConverters.h"

class RGBLED
{
public:
    RGBLED(const byte redPin, const byte greenPin, const byte bluePin);

    void setColor(RGBA rgba);

    void setColor(HSV hsv);

    void write(byte red, byte green, byte blue);
private:
    const byte redPin, greenPin, bluePin;
};

#endif