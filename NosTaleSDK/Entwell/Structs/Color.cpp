#include "Color.hpp"

namespace NosTaleSDK::Entwell::Structs
{
	Color::Color(uint8_t Red, uint8_t Green, uint8_t Blue, uint8_t Alpha)
		: blue(Blue)
		, green(Green)
		, red(Red)
		, alpha(Alpha)
	{}

	uint8_t Color::GetBlue() const
	{
		return blue;
	}

	uint8_t Color::GetGreen() const
	{
		return green;
	}

	uint8_t Color::GetRed() const
	{
		return red;
	}

	uint8_t Color::GetAlpha() const
	{
		return alpha;
	}

	void Color::SetBlue(uint8_t value)
	{
		blue = value;
	}

	void Color::SetGreen(uint8_t value)
	{
		green = value;
	}

	void Color::SetRed(uint8_t value)
	{
		red = value;
	}

	void Color::SetAlpha(uint8_t value)
	{
		alpha = value;
	}
}
