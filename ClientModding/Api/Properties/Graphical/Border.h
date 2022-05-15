#pragma once
#include <stdint.h>

/**
 * @brief Game widget position representation.
 */
class Border
{
public:
	Border()
		: topLeftX(0)
		, topLeftY(0)
		, botRightX(0)
		, botRightY(0)
	{}

	Border(int16_t X, int16_t Y, int16_t Width, int16_t Height)
		: topLeftX(X)
		, topLeftY(Y)
		, botRightX(X + Width)
		, botRightY(Y + Height)
	{}

	int16_t topLeftX;                       // 0x00
	int16_t topLeftY;                       // 0x02
	int16_t botRightX;                      // 0x04
	int16_t botRightY;                      // 0x06
};