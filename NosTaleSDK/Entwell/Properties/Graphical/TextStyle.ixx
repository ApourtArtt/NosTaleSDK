module;
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
		Enumerations::FontStyle fontStyle;						// 0x000
		Enumerations::TextShadowOrientation shadowOrientation;	// 0x001
		Bgra textBgra;											// 0x002
		Bgra shadowBgra;										// 0x006
		Enumerations::TextAlignment textAlignment;				// 0x00A
	};
	static_assert(sizeof(TextStyle) == 0xB, "TextStyle size isn't 0xB.");
	static_assert(sizeof(TextStyle) <= 0xB, "TextStyle size is upper than 0xB.");
	static_assert(sizeof(TextStyle) >= 0xB, "TextStyle size is lower than 0xB.");
#pragma pack(pop)
}