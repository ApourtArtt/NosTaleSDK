module;
export module TEWControlWidgetEX;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWControlWidgetEX : public TEWControlWidget
	{
	};
	static_assert(sizeof(TEWControlWidgetEX) == 0x68, "TEWControlWidgetEX size isn't 0x68.");
	static_assert(sizeof(TEWControlWidgetEX) <= 0x68, "TEWControlWidgetEX size is upper than 0x68.");
	static_assert(sizeof(TEWControlWidgetEX) >= 0x68, "TEWControlWidgetEX size is lower than 0x68.");
#pragma pack(pop)
}
