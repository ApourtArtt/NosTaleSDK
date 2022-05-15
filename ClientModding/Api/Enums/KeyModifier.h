#pragma once
#include <stdint.h>

/**
 * @brief Representation of the game key modifiers.
 */
enum class KeyModifier : uint8_t
{
	NO_MODIFIER = 0,
	SHIFT = 1,
	ALT = 2,
	ALTSHIFT = 3,
	CTRL = 4,
	CTRLSHIFT = 5,
	CTRLALT = 6,
	CTRLALTSHIFT = 7,
};
