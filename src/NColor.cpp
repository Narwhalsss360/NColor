#include "NColor.h"

RGBAColorContainer::RGBAColorContainer()
	: components{ 0, 0, 0, 0 }
{
}

RGBAColorContainer::RGBAColorContainer(byte red, byte green, byte blue, byte alpha)
	: red(red), green(green), blue(blue), alpha(alpha)
{
}

byte& RGBAColorContainer::operator[](unsigned short index)
{
	return components[index];
}

RGBA::RGBA()
	: hex(C_WHITE)
{
}

RGBA::RGBA(const xRGBA& hex)
	: hex(hex)
{
}

RGBA::RGBA(byte* colors)
	: hex(*(xRGBA*)colors)
{
}

RGBA::RGBA(byte red, byte green, byte blue, byte alpha = 255)
	: components(RGBAColorContainer(red, green, blue, alpha))
{
}

RGBA::RGBA(const HSV& hsv)
	: hex(C_WHITE)
{
	convertFromHSVtoRGBA(hsv);
}

void RGBA::convertFromHSVtoRGBA(const HSV& hsv)
{
}

HSV::HSV()
	: hue(0), saturation(0), value(0)
{
}

HSV::HSV(const RGBA& rgba)
	: hue(0), saturation(0), value(0)
{
	convertFromRGBAToHSV(rgba);
}

HSV::HSV(float hue, float saturation, float value)
	: hue(hue), saturation(saturation), value(value)
{
}

void HSV::convertFromRGBAToHSV(const RGBA& rgba)
{
}

Color::Color()
	: RGBA(), HSV()
{
}

Color::Color(const RGBA& rgba)
	: RGBA(rgba), HSV(rgba)
{
}

Color::Color(const HSV& hsv)
	: RGBA(hsv), HSV(hsv)
{
}

void Color::synchronize(BaseSynchronizes synchronizeBase)
{
	switch (synchronizeBase)
	{
	case SYNC_RGBA:
		convertFromHSVtoRGBA(*this);
		break;
	case SYNC_HSV:
		convertFromRGBAToHSV(*this);
		break;
	default:
		break;
	}
}

RGBLEDPins::RGBLEDPins(byte red, byte green, byte blue)
	: red(red), green(green), blue(blue)
{
}

RGBLED::RGBLED(const RGBLEDPins& pins)
	: pins(pins)
{
	for (byte i = 0; i < 3; i++)
		pinMode(pins.array[i], OUTPUT);
}

void RGBLED::setColor(const RGBA& color)
{
	write
	(
		color.components.red * (color.components.alpha / 255),
		color.components.green * (color.components.alpha / 255),
		color.components.blue * (color.components.alpha / 255)
	);
}

void RGBLED::write(byte red, byte green, byte blue)
{
	analogWrite(pins.red, red);
	analogWrite(pins.green, green);
	analogWrite(pins.blue, blue);
}

/*
HSV::HSV(float h, float s, float v)
{
	this->hue = (ZERO <= h && h <= 360) ? h : ZERO;
	this->saturation = (ZERO <= s && s <= 100) ? s : ZERO;
	this->value = (ZERO <= v && v <= 100) ? v : ZERO;
}

void Color::convertHexToRGB()
{
	this->rgb.red = this->hexCode >> 16;
	this->rgb.green = (this->hexCode & 0x00ff00) >> 8;
	this->rgb.blue = (this->hexCode & 0x0000ff);
}

void Color::convertHSVToRGB()
{
	float s = this->hsv.saturation / 100;
	float v = this->hsv.value / 100;
	float C = s * v;
	float X = C * (1 - abs(fmod(this->hsv.hue / 60.0, 2) - 1));
	float m = v - C;
	float r, g, b;

	if (this->hsv.hue >= ZERO && this->hsv.hue < 60) 
    {
		r = C, g = X, b = ZERO;
	}
	else if (this->hsv.hue >= 60 && this->hsv.hue < 120) 
    {
		r = X, g = C, b = ZERO;
	}
	else if (this->hsv.hue >= 120 && this->hsv.hue < 180) 
    {
		r = ZERO, g = C, b = X;
	}
	else if (this->hsv.hue >= 180 && this->hsv.hue < 240) 
    {
		r = ZERO, g = X, b = C;
	}
	else if (this->hsv.hue >= 240 && this->hsv.hue < 300) 
    {
		r = X, g = ZERO, b = C;
	}
	else 
    {
		r = C, g = ZERO, b = X;
	}

	this->rgb.red = (r + m) * 255;
	this->rgb.green = (g + m) * 255;
	this->rgb.blue = (b + m) * 255;
}

void Color::convertRGBToHex()
{
	this->hexCode |= this->rgb.red << 16;
	this->hexCode |= this->rgb.blue << 8;
	this->hexCode |= this->rgb.green;
}

void Color::convertRGBToHSV()
{
	float fCMax = max(max(this->rgb.red, this->rgb.green), this->rgb.blue);
	float fCMin = min(min(this->rgb.red, this->rgb.green), this->rgb.blue);
	float fDelta = fCMax - fCMin;

	if (fDelta > ZERO) 
    {
		if (fCMax == this->rgb.red) 
        {
			this->hsv.hue = 60 * (fmod(((this->rgb.green - this->rgb.blue) / fDelta), 6));
		}
		else if (fCMax == this->rgb.green) 
        {
			this->hsv.hue = 60 * (((this->rgb.blue - this->rgb.red) / fDelta) + 2);
		}
		else if (fCMax == this->rgb.blue) 
        {
			this->hsv.hue = 60 * (((this->rgb.red - this->rgb.green) / fDelta) + 4);
		}

		if (fCMax > ZERO) 
        {
			this->hsv.saturation = fDelta / fCMax;
		}
		else 
        {
			this->hsv.saturation = ZERO;
		}

		this->hsv.value = fCMax;
	}
	else 
    {
		this->hsv.hue = ZERO;
		this->hsv.saturation = ZERO;
		this->hsv.value = fCMax;
	}

	if (this->hsv.hue < ZERO) 
    {
		this->hsv.hue = 360 + this->hsv.hue;
	}
}
#pragma endregion
*/