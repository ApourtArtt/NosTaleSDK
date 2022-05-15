#pragma once
#include <stdint.h>

/**
 * @brief Game text shadow orientation representation.
 */
enum class TextShadowOrientation : uint8_t
{
	ShadowNone = 0,
	ShadowBottom = 1,
	ShadowBottomLeft = 2,
	ShadowBottomRight = 4,
	ShadowTop = 8,
	ShadowTopLeft = 16,
	ShadowTopRight = 32,
	ShadowLeft = 64,
	ShadowRight = 128,
	ShadowAll = 255,
};

inline TextShadowOrientation operator|(TextShadowOrientation a, TextShadowOrientation b)
{
	return static_cast<TextShadowOrientation>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

inline TextShadowOrientation operator&(TextShadowOrientation a, TextShadowOrientation b)
{
	return static_cast<TextShadowOrientation>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
}
