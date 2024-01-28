module;
export module TReadyWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TReadyWidget : public TLBSWidget
	{
		struct TEWGraphicButtonWidget* readyButton;    // 0x24
	};
	static_assert(sizeof(TReadyWidget) == 0x28, "TReadyWidget does not have a size of 0x28.");
#pragma pack(pop)
}