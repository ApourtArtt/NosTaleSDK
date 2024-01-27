module;
export module TImpossibleIconWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TImpossibleIconWidget : public TLBSWidget
	{
		struct TEWControlWidgetEX* control1;    // 0x24
		struct TEWControlWidgetEX* control2;    // 0x28
	};
	static_assert(sizeof(TImpossibleIconWidget) == 0x2C, "TImpossibleIconWidget does not have a size of 0x2C.");
#pragma pack(pop)
}