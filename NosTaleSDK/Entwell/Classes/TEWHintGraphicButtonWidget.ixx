module;
#include <stdint.h>
export module TEWHintGraphicButtonWidget;
import TEWGraphicButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWHintGraphicButtonWidget : public TEWGraphicButtonWidget
	{
		char unknown37[20];						// 0x0DC
		TEWCustomPanelWidget* unknown38;		// 0x0F0
		struct TEWLabel* unknown39;				// 0x0F4
		uint32_t unknown40;						// 0x0F8
	};
	static_assert(sizeof(TEWHintGraphicButtonWidget) == 0xFC, "TEWHintGraphicButtonWidget size isn't 0xFC.");
	static_assert(sizeof(TEWHintGraphicButtonWidget) <= 0xFC, "TEWHintGraphicButtonWidget size is upper than 0xFC.");
	static_assert(sizeof(TEWHintGraphicButtonWidget) >= 0xFC, "TEWHintGraphicButtonWidget size is lower than 0xFC.");
#pragma pack(pop)
}