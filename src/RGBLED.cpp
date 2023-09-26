#include "RGBLED.h"

RGBLED::RGBLED(const byte redPin, const byte greenPin, const byte bluePin)
    : redPin(redPin), greenPin(greenPin), bluePin(bluePin)
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void RGBLED::setColor(RGBA rgba)
{
    write
    (
        rgba.colors.red * (rgba.colors.alpha / 255),
        rgba.colors.green * (rgba.colors.alpha / 255),
        rgba.colors.blue * (rgba.colors.alpha / 255)
    );
}

void RGBLED::setColor(HSV hsv)
{
    setColor(convertToRGBA(hsv));
}

void RGBLED::write(byte red, byte green, byte blue)
{
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}