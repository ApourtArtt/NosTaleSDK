module;
#include <stdint.h>
export module TextStyle;
import Bgra;
import TextAlignment;
import TextShadowOrientation;
import FontStyle;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct TextStyle
	{
		NosTaleSDK::Entwell::Enumerations::FontStyle fontStyle;						// 0x000
		NosTaleSDK::Entwell::Enumerations::TextShadowOrientation shadowOrientation;	// 0x001
		struct Bgra textBgra;														// 0x002
		struct Bgra shadowBgra;														// 0x006
		NosTaleSDK::Entwell::Enumerations::TextAlignment textAlignement;			// 0x00A
	};
	static_assert(sizeof(TextStyle) == 0xB, "TextStyle size isn't 0xB.");
	static_assert(sizeof(TextStyle) <= 0xB, "TextStyle size is upper than 0xB.");
	static_assert(sizeof(TextStyle) >= 0xB, "TextStyle size is lower than 0xB.");
#pragma pack(pop)
}