module;
export module TEWRollOverButtonWidget;
import TEWGraphicButtonWidget;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWRollOverButtonWidget : public TEWGraphicButtonWidget
	{
		char unknown36[4];														// 0x0DC
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknown37;	// 0x0E0
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknown38;	// 0x0E8
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknown39;	// 0x0F0
		struct NosTaleSDK::Entwell::Properties::Logical::Callback unknown40;	// 0x0F8
		uint32_t unknown41;														// 0x100
	};
	static_assert(sizeof(TEWRollOverButtonWidget) == 0x104, "TEWRollOverButtonWidget size isn't 0x104.");
	static_assert(sizeof(TEWRollOverButtonWidget) <= 0x104, "TEWRollOverButtonWidget size is upper than 0x104.");
	static_assert(sizeof(TEWRollOverButtonWidget) >= 0x104, "TEWRollOverButtonWidget size is lower than 0x104.");
#pragma pack(pop)
}