#ifndef Color_h
#define Color_h

#include "RGBA.h"
#include "HSV.h"

class Color {
public:
    Color();

    Color(const RGBA& rgba);

    Color(const HSV& hsv);

    uint8_t red() const;

    void setRed(uint8_t red);

    uint8_t green() const;

    void setGreen(uint8_t green);

    uint8_t blue() const;

    void setBlue(uint8_t blue);

    uint8_t alpha() const;

    void setAlpha(uint8_t alpha);

    float hue() const;

    void setHue(float hue);

    float saturation() const;

    void setSaturation(float saturation);

    float value() const;

    void setValue(float value);

    RGBA asRGBA() const;

    HSV asHSV() const;

    Color& operator=(const RGBA& rgba);

    Color& operator=(const HSV& hsv);

    operator RGBA();

    operator HSV();

    operator const RGBA&() const;

    operator const HSV&() const;

private:
    RGBA rgba;
    HSV hsv;
};

#endif
