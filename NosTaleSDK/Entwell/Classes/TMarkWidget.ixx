module;
#include <stdint.h>
export module TMarkWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMarkWidget : public TLBSWidget
	{
		struct TEWGraphicButtonWidget* button;	// 0x024
		uint32_t unknown5;						// 0x028
		uint8_t unknown6;						// 0x02C
		char unknown7[3];						// 0x02D
	};
	static_assert(sizeof(TMarkWidget) == 0x30, "TMarkWidget size isn't 0x30.");
	static_assert(sizeof(TMarkWidget) <= 0x30, "TMarkWidget size is upper than 0x30.");
	static_assert(sizeof(TMarkWidget) >= 0x30, "TMarkWidget size is lower than 0x30.");
#pragma pack(pop)
}