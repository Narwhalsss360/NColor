#include <NColor.h>

#define RED 7
#define GREEN 8
#define BLUE 9

ColorLED led = ColorLED(RED, GREEN, BLUE)

void setup()
{
}

void loop()
{
    HSV hsv = (HSV)led;
    if (hsv.hue == 360)
        hsv.hue = 0;
    else
        hsv.hue += 1;
    led = hsv;
    delay(125);
}