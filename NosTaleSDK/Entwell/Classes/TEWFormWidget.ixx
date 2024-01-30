module;
export module TEWFormWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWFormWidget : public TEWCustomFormWidget
	{
		char unknown38[4];	// 0x0BC
		char resizeFlag;	// 0x0C0
		char unknown39[3];	// 0x0C1
	};
	static_assert(sizeof(TEWFormWidget) == 0xC4, "TEWFormWidget size isn't 0xC4.");
	static_assert(sizeof(TEWFormWidget) <= 0xC4, "TEWFormWidget size is upper than 0xC4.");
	static_assert(sizeof(TEWFormWidget) >= 0xC4, "TEWFormWidget size is lower than 0xC4.");
#pragma pack(pop)
}