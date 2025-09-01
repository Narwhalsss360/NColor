#ifndef ColorLED_h
#define ColorLED_h

#include "Color.h"

class ColorLED {
public:
    ColorLED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, Color initialColor = Color());

    const Color& color() const;

    const RGBA& rgba() const;

    const HSV& hsv() const;

    operator const Color&() const;

    operator const RGBA&() const;

    operator const HSV&() const;

    ColorLED& operator=(const Color& color);

    ColorLED& operator=(const RGBA& rgba);

    ColorLED& operator=(const HSV& hsv);

private:
    void write();

    uint8_t _redPin, _greenPin, _bluePin;
    Color _color;
};

#endif
