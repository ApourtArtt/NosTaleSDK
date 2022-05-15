#pragma once
#include "TextShadowOrientation.h"
#include "Bgra.h"
#include "TextAlignment.h"
#pragma pack(push, 1)

/**
 * @brief Game text style representation.
 */
class TextStyle
{
public:
	TextStyle()
		: TextStyle(0, TextShadowOrientation::ShadowNone, Bgra(255, 255, 255, 255), Bgra(255, 255, 255, 255), TextAlignment::CenteredLeft)
	{}

	TextStyle(uint8_t FontStyle)
		: TextStyle(FontStyle, TextShadowOrientation::ShadowNone, Bgra(255, 255, 255, 255), Bgra(255, 255, 255, 255), TextAlignment::CenteredLeft)
	{}

	TextStyle(uint8_t FontStyle, TextShadowOrientation ShadowOrientation, Bgra TextBgra, Bgra ShadowBgra, TextAlignment TextAlignement)
		: fontStyle(FontStyle)
		, shadowOrientation(ShadowOrientation)
		, textBgra(TextBgra)
		, shadowBgra(ShadowBgra)
		, textAlignement(TextAlignement)
	{}

	uint8_t fontStyle;							// 0x00
	TextShadowOrientation shadowOrientation;	// 0x01
	Bgra textBgra;								// 0x02
	Bgra shadowBgra;							// 0x06
	TextAlignment textAlignement;				// 0x0A
};
static_assert(sizeof(TextStyle) == 0x0B, "TextStyle does not have a size of 0x0B.");

#pragma pack(pop)