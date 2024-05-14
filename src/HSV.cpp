#include "HSV.h"

HSV::HSV(float hue, float saturation, float value)
    : hue(hue), saturation(saturation), value(value)
{}

HSV::HSV(const RGBA& rgba)
    : HSV((HSV)rgba)
{
}

HSV::operator RGBA() const {
    return RGBA(*this);
}
