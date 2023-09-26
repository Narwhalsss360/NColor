#ifndef RGBAStructure_h
#define RGBAStructure_h

#include <stdint.h>

typedef uint32_t xRGBA;

struct RGBAStructure
{
    RGBAStructure(const uint8_t& red = 0xFF, const uint8_t& green = 0xFF, const uint8_t& blue = 0xFF, const uint8_t& alpha = 0xFF);

    uint8_t
        alpha,
        blue,
        green,
        red;
};

#endif