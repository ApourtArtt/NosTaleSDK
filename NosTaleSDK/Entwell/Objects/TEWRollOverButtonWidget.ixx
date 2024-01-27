module;
export module TEWRollOverButtonWidget;
import TEWGraphicButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWRollOverButtonWidget : public TEWGraphicButtonWidget
	{
		char pad[0x104 - 0xDC]; // 0xDC
	};
	static_assert(sizeof(TEWRollOverButtonWidget) == 0x104, "TEWRollOverButtonWidget does not have a size of 0x104.");
#pragma pack(pop)
}