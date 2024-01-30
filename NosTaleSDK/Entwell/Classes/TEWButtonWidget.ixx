module;
#include <stdint.h>
export module TEWButtonWidget;
import TEWGraphicButtonWidget;
import TextStyle;
import TextPosition;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWButtonWidget : public TEWGraphicButtonWidget
	{
		char unknown37[4];																// 0x0DC
		uint16_t unknown38;																// 0x0E0
		uint16_t unknown39;																// 0x0E2
		struct NosTaleSDK::Entwell::Properties::Graphical::TextStyle textStyle;			// 0x0E4
		uint32_t unknown40;																// 0x0EF
		uint32_t unknown41;																// 0x0F3
		uint16_t unknown42;																// 0x0F7
		uint8_t unknown43;																// 0x0F9
		uint32_t unknown44;																// 0x0FA
		uint32_t unknown45;																// 0x0FE
		uint16_t unknown46;																// 0x102
		uint8_t unknown47;																// 0x104
		uint8_t unknown48;																// 0x105
		char unknown49[2];																// 0x106
		struct NosTaleSDK::Entwell::Properties::Graphical::TextPosition textPosition;	// 0x108
	};
	static_assert(sizeof(TEWButtonWidget) == 0x118, "TEWButtonWidget size isn't 0x118.");
	static_assert(sizeof(TEWButtonWidget) <= 0x118, "TEWButtonWidget size is upper than 0x118.");
	static_assert(sizeof(TEWButtonWidget) >= 0x118, "TEWButtonWidget size is lower than 0x118.");
#pragma pack(pop)
}
