module;
#include <stdint.h>
export module TEWCaptionBar;
import TEWParentMoveWidget;
import TextStyle;
import TextPosition;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWCaptionBar : public TEWParentMoveWidget
	{
		int16_t unknown21;									// 0x078
		bool unknown22;										// 0x07A
		bool unknown23;										// 0x07B
		bool unknown24;										// 0x07C
		bool unknown25;										// 0x07D
		uint32_t unknown26;									// 0x07E
		uint32_t unknown27;									// 0x082
		uint32_t unknown28;									// 0x086
		uint32_t unknown29;									// 0x08A
		uint32_t unknown30;									// 0x08E
		uint32_t unknown31;									// 0x092
		Properties::Graphical::TextStyle textStyle;			// 0x096
		char unknown32[3];									// 0x0A1
		Properties::Graphical::TextPosition textPosition;	// 0x0A4
	};
	static_assert(sizeof(TEWCaptionBar) == 0xB4, "TEWCaptionBar size isn't 0xB4.");
	static_assert(sizeof(TEWCaptionBar) <= 0xB4, "TEWCaptionBar size is upper than 0xB4.");
	static_assert(sizeof(TEWCaptionBar) >= 0xB4, "TEWCaptionBar size is lower than 0xB4.");
#pragma pack(pop)
}
