module;
#include <stdint.h>
export module TextStyle;
import Bgra;
import TextAlignment;
import TextShadowOrientation;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct TextStyle
	{
		uint8_t fontStyle;															// 0x00
		NosTaleSDK::Entwell::Enumerations::TextShadowOrientation shadowOrientation;	// 0x01
		struct Bgra textBgra;														// 0x02
		struct Bgra shadowBgra;														// 0x06
		NosTaleSDK::Entwell::Enumerations::TextAlignment textAlignement;			// 0x0A
	};
	static_assert(sizeof(TextStyle) == 0xB, "TextStyle does not have a size of 0xB.");
#pragma pack(pop)
}