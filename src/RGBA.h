#ifndef RGBA_h
#define RGBA_h

#include "RGBAStructure.h"

struct RGBA
{
	RGBA(const xRGBA& hex);

	RGBA(const uint8_t& red = 0xFF, const uint8_t& green = 0xFF, const uint8_t& blue = 0xFF, const uint8_t& alpha = 0xFF);

	union
	{
		RGBAStructure colors;
		xRGBA hex;
	};
};

#endif