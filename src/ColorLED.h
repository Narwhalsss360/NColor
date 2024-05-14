#ifndef ColorLED_h
#define ColorLED_h

#include "Color.h"

class ColorLED {
public:
    ColorLED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, Color initialColor = Color());

    operator Color() const;

    operator RGBA() const;

    operator HSV() const;

    ColorLED& operator=(const Color& color);

    ColorLED& operator=(const RGBA& rgba);

    ColorLED& operator=(const HSV& hsv);

private:
    void write();

    uint8_t redPin, greenPin, bluePin;
    Color color;
};

#endif
