#ifndef ColorConverters_h
#define ColorConverters_h

struct RGBA;
struct HSV;

RGBA convertToRGBA(const HSV& hsv);

HSV convertToHSV(const RGBA& rgba);

#endif