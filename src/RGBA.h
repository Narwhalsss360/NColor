#ifndef RGBA_h
#define RGBA_h

#include <stdint.h>

struct HSV;

union RGBA {
    struct Components {
        uint8_t
            blue,
            green,
            red,
            alpha;
    } components;

    uint32_t hex;

    RGBA(uint32_t hex = 0);

    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0);

    RGBA(Components components);

    explicit RGBA(const HSV& hsv);

    operator HSV() const;
};

#endif
