#include "Color.h"

Color::Color()
    : rgba(RGBA()), hsv(HSV())
{}

Color::Color(const RGBA& rgba)
    : rgba(rgba), hsv((HSV)rgba)
{}

Color::Color(const HSV& hsv)
    : rgba((RGBA)hsv), hsv(hsv)
{}

uint8_t Color::red() const {
    return rgba.components.red;
}

void Color::setRed(uint8_t red) {
    rgba.components.red = red;
    hsv = (RGBA)rgba;
}

uint8_t Color::green() const {
    return rgba.components.green;
}

void Color::setGreen(uint8_t green) {
    rgba.components.green = green;
    hsv = (RGBA)rgba;
}

uint8_t Color::blue() const {
    return rgba.components.blue;
}

void Color::setBlue(uint8_t blue) {
    rgba.components.blue = blue;
    hsv = (HSV)rgba;
}

uint8_t Color::alpha() const {
    return rgba.components.alpha;
}

void Color::setAlpha(uint8_t alpha) {
    rgba.components.alpha = alpha;
}

float Color::hue() const {
    return hsv.hue;
}

void Color::setHue(float hue) {
    hsv.hue = hue;
    rgba = (RGBA)hsv;
}

float Color::saturation() const {
    return hsv.saturation;
}

void Color::setSaturation(float saturation) {
    hsv.saturation = saturation;
    rgba = (RGBA)hsv;
}

float Color::value() const {
    return hsv.value;
}

void Color::setValue(float value) {
    hsv.value = value;
    rgba = (RGBA)hsv;
}

RGBA Color::asRGBA() const {
    return rgba;
}

HSV Color::asHSV() const {
    return hsv;
}

Color& Color::operator=(const RGBA& rgba) {
    this->rgba = rgba;
    hsv = (RGBA)rgba;
    return *this;
}

Color& Color::operator=(const HSV& hsv) {
    this->hsv = hsv;
    rgba = (RGBA)hsv;
    return *this;
}

Color::operator RGBA() {
    return rgba;
}

Color::operator HSV() {
    return hsv;
}

Color::operator const RGBA&() const {
    return rgba;
}

Color::operator const HSV&() const {
    return hsv;
}
