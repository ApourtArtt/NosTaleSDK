module;
export module TEWGraphicButtonWidget;
import TEWCustomButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)

	export struct TEWGraphicButtonWidget : public TEWCustomButtonWidget
	{
		uint8_t unknown35;	// 0x0D8
		char unknown36[3];	// 0x0D9
	};
	static_assert(sizeof(TEWGraphicButtonWidget) == 0xDC, "TEWGraphicButtonWidget size isn't 0xDC.");
	static_assert(sizeof(TEWGraphicButtonWidget) <= 0xDC, "TEWGraphicButtonWidget size is upper than 0xDC.");
	static_assert(sizeof(TEWGraphicButtonWidget) >= 0xDC, "TEWGraphicButtonWidget size is lower than 0xDC.");
#pragma pack(pop)
}