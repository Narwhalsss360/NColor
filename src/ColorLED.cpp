#include "ColorLED.h"
#include <Arduino.h>

ColorLED::ColorLED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, Color initialColor)
    : redPin(redPin), greenPin(greenPin), bluePin(bluePin), color(initialColor)
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

ColorLED::operator Color() const {
    return color;
}

ColorLED::operator RGBA() const {
    return color.asRGBA();
}

ColorLED::operator HSV() const {
    return color.asHSV();
}

ColorLED& ColorLED::operator=(const Color& color) {
    this->color = color;
    write();
    return *this;
}

ColorLED& ColorLED::operator=(const RGBA& rgba) {
    color = rgba;
    write();
    return *this;
}

ColorLED& ColorLED::operator=(const HSV& hsv) {
    color = hsv;
    write();
    return *this;
}

void ColorLED::write() {
    const RGBA& rgba = (const RGBA&)color;
    analogWrite(redPin, rgba.components.red);
    analogWrite(redPin, rgba.components.green);
    analogWrite(redPin, rgba.components.blue);
}
