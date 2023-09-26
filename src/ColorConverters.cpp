#include "ColorConverters.h"
#include "RGBA.h"
#include "HSV.h"

RGBA convertToRGBA(const HSV& hsv)
{
    float s = hsv.saturation / 100;
	float v = hsv.value / 100;
	float C = s * v;
	float X = C * (1 - abs(fmod(hsv.hue / 60.0, 2) - 1));
	float m = v - C;
	float r, g, b;

	if (hsv.hue >= 0 && hsv.hue < 60)
		r = C, g = X, b = 0;
	else if (hsv.hue >= 60 && hsv.hue < 120) 
		r = X, g = C, b = 0;
	else if (hsv.hue >= 120 && hsv.hue < 180) 
		r = 0, g = C, b = X;
	else if (hsv.hue >= 180 && hsv.hue < 240) 
		r = 0, g = X, b = C;
	else if (hsv.hue >= 240 && hsv.hue < 300) 
		r = X, g = 0, b = C;
	else 
		r = C, g = 0, b = X;

    return RGBA((r + m) * 255, (g + m) * 255, (b + m) * 255);
}

HSV convertToHSV(const RGBA& rgba)
{
    float colorMax = max(max(rgba.colors.red, rgba.colors.green), rgba.colors.blue);
    float colorMin = min(min(rgba.colors.red, rgba.colors.green), rgba.colors.blue);
    float colorDifference = colorMax - colorMin;

    float
        h = 0,
        s = 0,
        v = colorMax;

    if (colorDifference)
    {
        if (colorMax == rgba.colors.red)
            h = 60 * fmod((rgba.colors.green - rgba.colors.blue) / colorDifference, 6);
        else if (colorMax == rgba.colors.green)
            h = 60 * fmod((rgba.colors.blue - rgba.colors.red) / colorDifference, 6);
        else
            h = 60 * fmod((rgba.colors.red - rgba.colors.green) / colorDifference, 6);

        if (colorMax)
            s = colorDifference / colorMax;

        v = colorMax;
    }

    if (h < 0)
        h += 360;

    return HSV(h, s, v);
}