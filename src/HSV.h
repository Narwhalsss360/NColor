#ifndef HSV_h
#define HSV_h

#include "RGBA.h"

struct HSV {
    float
        hue,
        saturation,
        value;

    HSV(float hue = 0, float saturation = 0, float value = 0);

    explicit HSV(const RGBA& rgba);

    operator RGBA() const;
};


#endif
