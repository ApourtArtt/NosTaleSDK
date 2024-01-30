module;
#include <stdint.h>
export module TEWTextOut;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWTextOut : public TEWControlWidgetEX
	{
		struct TLBSTextRender* textRender;									// 0x068
		uint8_t unknown20;													// 0x06C
		struct NosTaleSDK::Entwell::Properties::Graphical::Bgra textColor;	// 0x06D
		uint8_t unknown21;													// 0x071
		uint8_t unknown22;													// 0x072
		uint8_t unknown23;													// 0x073
		char unknown24;														// 0x074
		uint8_t unknown25;													// 0x075
		bool isBgTransparent;												// 0x076
		char unknown26;														// 0x077
	};
	static_assert(sizeof(TEWTextOut) == 0x78, "TEWTextOut size isn't 0x78.");
	static_assert(sizeof(TEWTextOut) <= 0x78, "TEWTextOut size is upper than 0x78.");
	static_assert(sizeof(TEWTextOut) >= 0x78, "TEWTextOut size is lower than 0x78.");
#pragma pack(pop)
}