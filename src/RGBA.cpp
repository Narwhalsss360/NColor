#include "RGBA.h"

RGBA::RGBA(const xRGBA& hex)
    : hex(hex)
{
}

RGBA::RGBA(const uint8_t& red = 0xFF, const uint8_t& green = 0xFF, const uint8_t& blue = 0xFF, const uint8_t& alpha = 0xFF)
    : colors(red, green, blue, alpha)
{
}