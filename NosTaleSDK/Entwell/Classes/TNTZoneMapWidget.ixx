module;
#include <stdint.h>
export module TNTZoneMapWidget;
import TEWPopupPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTZoneMapWidget : public TEWPopupPanelWidget
	{
		char unknown32[16];								// 0x0AC
		struct TEWHintGraphicButtonWidget* unknown33;	// 0x0BC
		struct TEWGraphicButtonWidget* unknown34;		// 0x0C0
		TEWGraphicButtonWidget* unknown35;				// 0x0C4
		TEWGraphicButtonWidget* unknown36;				// 0x0C8
		uint32_t unknown37;								// 0x0CC
	};
	static_assert(sizeof(TNTZoneMapWidget) == 0xD0, "TNTZoneMapWidget size isn't 0xD0.");
	static_assert(sizeof(TNTZoneMapWidget) <= 0xD0, "TNTZoneMapWidget size is upper than 0xD0.");
	static_assert(sizeof(TNTZoneMapWidget) >= 0xD0, "TNTZoneMapWidget size is lower than 0xD0.");
#pragma pack(pop)
}