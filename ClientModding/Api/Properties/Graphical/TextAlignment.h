#pragma once
#include <stdint.h>

/**
 * @brief Game text alignment representation.
 */
enum class TextAlignment : uint8_t
{
	TopLeft = 0,
	CenteredLeft = 1,
	CenteredRight = 2,
	CenteredCentered = 3
};
