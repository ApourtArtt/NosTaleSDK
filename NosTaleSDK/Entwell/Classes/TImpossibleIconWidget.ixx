module;
export module TImpossibleIconWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TImpossibleIconWidget : public TLBSWidget
	{
		struct TEWControlWidgetEX* control1;    // 0x024
		struct TEWControlWidgetEX* control2;    // 0x028
	};
	static_assert(sizeof(TImpossibleIconWidget) == 0x2C, "TImpossibleIconWidget size isn't 0x2C.");
	static_assert(sizeof(TImpossibleIconWidget) <= 0x2C, "TImpossibleIconWidget size is upper than 0x2C.");
	static_assert(sizeof(TImpossibleIconWidget) >= 0x2C, "TImpossibleIconWidget size is lower than 0x2C.");
#pragma pack(pop)
}