#ifndef HSV_h
#define HSV_h

struct HSV
{
	HSV(const float& hue = 0, const float& saturation = 100, const float& value = 100);

	float
		hue,
		saturation,
		value;
};

#endif