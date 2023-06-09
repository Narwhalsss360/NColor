#ifndef NColor_h
#define NColor_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <NDefs.h>
#include <NFuncs.h>
#include "CommonColors.h"

enum BaseSynchronizes
{
	SYNC_RGBA,
	SYNC_HSV
};

typedef uint32_t xRGBA;

struct RGBA;
struct HSV;

struct RGBAColorContainer
{
	RGBAColorContainer();

	RGBAColorContainer(byte red, byte green, byte blue, byte alpha);

	byte& operator[](unsigned short index);

	union
	{
		byte alpha, red, green, blue;
		byte components[4];
	};
};

struct RGBA
{
	RGBA();

	RGBA(const xRGBA& hex);

	RGBA(byte* colors);

	RGBA(byte red, byte green, byte blue, byte alpha = 255);

	RGBA(const HSV& hsv);

	void convertFromHSVtoRGBA(const HSV& hsv);

	union
	{
		xRGBA hex;
		RGBAColorContainer components;
	};
};

struct HSV
{
	HSV();

	HSV(const RGBA& rgba);

	HSV(float hue, float saturation, float value);

	void convertFromRGBAToHSV(const RGBA& rgba);

	float hue, saturation, value;
};

struct Color : RGBA, HSV
{
	Color();

	Color(const RGBA& rgba);

	Color(const HSV& hsv);

	void synchronize(BaseSynchronizes synchronizeBase);
};

struct RGBLEDPins
{
	RGBLEDPins(byte red, byte green, byte blue);

	union
	{
		const byte red, green, blue;
		const byte array[3];
	};
};

class RGBLED
{
public:
	RGBLED(const RGBLEDPins& pins);

	void setColor(const RGBA& color);

	void write(byte red, byte green, byte blue);

private:
	const RGBLEDPins pins;
};

/*
typedef unsigned long HEXRGB;

typedef struct RGB;

struct RGBA
{
	byte red,
		green,
		blue,
		alpha;
	RGBA();
	RGBA(byte, byte, byte, byte);
	RGBA(RGB);
};

struct RGB
{
	byte red,
		green,
		blue;
	RGB();
	RGB(byte, byte, byte);
	RGB(RGBA);
};

struct HSV
{
	float hue,
		saturation,
		value;
	HSV();
	HSV(float, float, float);
};

struct Color
{
public:
	RGB rgb;
	HSV hsv;
	HEXRGB hexCode;
private:
	void convertHexToRGB();
	void convertHSVToRGB();
	void convertRGBToHex();
	void convertRGBToHSV();
public:
	Color();
	Color(HEXRGB);
	Color(HSV);
	Color(RGB);
};

class RGBLed
{
public:
	RGBLed(byte, byte, byte);
	void setColor(RGB);
	void setColor(RGBA);
	void setColor(Color);
	void setColor(byte, byte, byte);
	void setColor(byte, byte, byte, byte);
	void setBrightness(byte);
	void on();
	void off();
	RGBA currentColor;
private:
	void write(byte, byte, byte);
	const byte redPin;
	const byte greenPin;
	const byte bluePin;
};*/
#endif