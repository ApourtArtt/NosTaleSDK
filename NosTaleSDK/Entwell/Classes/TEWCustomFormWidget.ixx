module;
#include <stdint.h>
export module TEWCustomFormWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWCustomFormWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];					// 0x0A4
		struct TEWCaptionBar* captionBar;	// 0x0A8
		uint8_t unknown31;					// 0x0AC
		uint8_t unknown32;					// 0x0AD
		uint8_t unknown33;					// 0x0AE
		uint32_t unknown34;					// 0x0AF
		uint32_t unknown35;					// 0x0B3
		char unknown36;						// 0x0B4
		TLBSWidget* unknown37;				// 0x0B8
	};
	static_assert(sizeof(TEWCustomFormWidget) == 0xBC, "TEWCustomFormWidget size isn't 0xBC.");
	static_assert(sizeof(TEWCustomFormWidget) <= 0xBC, "TEWCustomFormWidget size is upper than 0xBC.");
	static_assert(sizeof(TEWCustomFormWidget) >= 0xBC, "TEWCustomFormWidget size is lower than 0xBC.");
#pragma pack(pop)
}
