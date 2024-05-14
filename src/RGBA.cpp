#include "RGBA.h"
#include "HSV.h"

#include <Arduino.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

RGBA::RGBA(uint32_t hex) : hex(hex) {}

RGBA::RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    : hex(0)
{
    components.red = red;
    components.green = green;
    components.blue = blue;
    components.alpha = alpha;
}

RGBA::RGBA(Components components)
    : hex(0)
{
    this->components = components;
}

RGBA::RGBA(const HSV& hsv)
    : hex(0)
{
    components.alpha = 255;

    float s = hsv.saturation / 100;
    float v = hsv.value / 100;
    float C = s * v;
    float X = C * (1 - abs(fmod(hsv.hue / 60.0, 2) - 1));
    float m = v - C;
    float r, g, b;

    if (hsv.hue >= 0 && hsv.hue < 60)
        r = C, g = X, b = 0;
    else if (hsv.hue >= 60 && hsv.hue < 120) 
        r = X, g = C, b = 0;
    else if (hsv.hue >= 120 && hsv.hue < 180) 
        r = 0, g = C, b = X;
    else if (hsv.hue >= 180 && hsv.hue < 240) 
        r = 0, g = X, b = C;
    else if (hsv.hue >= 240 && hsv.hue < 300) 
        r = X, g = 0, b = C;
    else 
        r = C, g = 0, b = X;

    components.red = (r + m) * 255;
    components.green = (g + m) * 255;
    components.blue = (b + m) * 255;
}

RGBA::operator HSV() const {
    float colorMax = max(max(components.red, components.green), components.blue);
    float colorMin = min(min(components.red, components.green), components.blue);
    float colorDifference = colorMax - colorMin;

    float
        h = 0,
        s = 0,
        v = colorMax;

    if (colorDifference)
    {
        if (colorMax == components.red)
            h = 60 * fmod((components.green - components.blue) / colorDifference, 6);
        else if (colorMax == components.green)
            h = 60 * fmod((components.blue - components.red) / colorDifference, 6);
        else
            h = 60 * fmod((components.red - components.green) / colorDifference, 6);

        if (colorMax)
            s = colorDifference / colorMax;

        v = colorMax;
    }

    if (h < 0)
        h += 360;

    return HSV(h, s, v);
}
