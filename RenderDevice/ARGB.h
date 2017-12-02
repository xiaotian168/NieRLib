
#pragma once

class ARGB
{
public:

	inline static unsigned int MakeARGB(const unsigned char uAlpha, const unsigned char uRed, const unsigned char uGreen, const unsigned char uBlue)
	{
		return (uAlpha << 24) | (uRed << 16) | (uGreen << 8) | uBlue;
	}

	inline static unsigned int MakeXRGB(const unsigned char uRed, const unsigned char uGreen, const unsigned char uBlue)
	{
		return MakeARGB(0xFF, uRed, uGreen, uBlue);
	}

	inline static unsigned char GetA(const unsigned int uARGB)
	{
		return (unsigned char)((uARGB & 0xFF000000) >> 24);
	}

	inline static unsigned char GetR(const unsigned int uARGB)
	{
		return (unsigned char)((uARGB & 0x00FF0000) >> 16);
	}

	inline static unsigned char GetG(const unsigned int uARGB)
	{
		return (unsigned char)((uARGB & 0x0000FF00) >> 8);
	}

	inline static unsigned char GetB(const unsigned int uARGB)
	{
		return (unsigned char)(uARGB & 0x000000FF);
	}
};
