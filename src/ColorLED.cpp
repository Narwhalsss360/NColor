#include "ColorLED.h"
#include <Arduino.h>

ColorLED::ColorLED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, Color initialColor)
    : _redPin(redPin), _greenPin(greenPin), _bluePin(bluePin), _color(initialColor)
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

const Color& ColorLED::color() const {
    return _color;
}

const RGBA& ColorLED::rgba() const {
    return _color.asRGBA();
}

const HSV& ColorLED::hsv() const {
    return _color.asHSV();
}

ColorLED::operator const Color&() const {
    return _color;
}

ColorLED::operator const RGBA&() const {
    return _color.asRGBA();
}

ColorLED::operator const HSV&() const {
    return _color.asHSV();
}

ColorLED& ColorLED::operator=(const Color& color) {
    _color = color;
    write();
    return *this;
}

ColorLED& ColorLED::operator=(const RGBA& rgba) {
    _color = rgba;
    write();
    return *this;
}

ColorLED& ColorLED::operator=(const HSV& hsv) {
    _color = hsv;
    write();
    return *this;
}

void ColorLED::write() {
    const RGBA& rgba = _color.asRGBA();
    analogWrite(_redPin, rgba.components.red);
    analogWrite(_greenPin, rgba.components.green);
    analogWrite(_bluePin, rgba.components.blue);
}
