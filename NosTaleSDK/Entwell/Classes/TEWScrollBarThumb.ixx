module;
export module TEWScrollBarThumb;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWScrollBarThumb : public TEWCustomPanelWidget
	{
		char unknown30[4];
	};
	static_assert(sizeof(TEWScrollBarThumb) == 0xA8, "TEWScrollBarThumb size isn't 0xA8.");
	static_assert(sizeof(TEWScrollBarThumb) <= 0xA8, "TEWScrollBarThumb size is upper than 0xA8.");
	static_assert(sizeof(TEWScrollBarThumb) >= 0xA8, "TEWScrollBarThumb size is lower than 0xA8.");
#pragma pack(pop)
}