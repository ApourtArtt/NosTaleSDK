module;
export module TReadyWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TReadyWidget : public TLBSWidget
	{
		struct TEWGraphicButtonWidget* readyButton;    // 0x024
	};
	static_assert(sizeof(TReadyWidget) == 0x28, "TReadyWidget size isn't 0x28.");
	static_assert(sizeof(TReadyWidget) <= 0x28, "TReadyWidget size is upper than 0x28.");
	static_assert(sizeof(TReadyWidget) >= 0x28, "TReadyWidget size is lower than 0x28.");
#pragma pack(pop)
}