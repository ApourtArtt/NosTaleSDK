#pragma once
#include <stdint.h>

/**
 * @brief Game BGRA color representation.
 */
class Bgra
{
public:
	Bgra(uint8_t Blue, uint8_t Green, uint8_t Red, uint8_t Alpha)
		: blue(Blue)
		, green(Green)
		, red(Red)
		, alpha(Alpha)
	{}

	uint8_t blue;	// 0x00
	uint8_t green;	// 0x01
	uint8_t red;	// 0x02
	uint8_t alpha;	// 0x03
};
