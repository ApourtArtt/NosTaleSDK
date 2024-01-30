module;
#include <stdint.h>
export module TNTRiskMapWidget;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTRiskMapWidget : public TEWCustomPanelWidget
	{
		char unknown30[4];						// 0x0A4
		uint16_t unknown31;						// 0x0A8
		uint16_t unknown32;						// 0x0AA
		uint16_t unknown33;						// 0x0AC
		uint16_t unknown34;						// 0x0AE
		uint8_t unknown35;						// 0x0B0
		uint8_t unknown36;						// 0x0B1
		char unknown37[2];						// 0x0B2
		uint32_t unknown38;						// 0x0B4
		struct TRiskFieldMapWidget* unknown39;	// 0x0B8
		char unknown40[4];						// 0x0B2
		struct TEWCustomPanelWidget* unknown41;	// 0x0C0
		uint16_t unknown42;						// 0x0C4
		char unknown43[2];						// 0x0C6
	};
	static_assert(sizeof(TNTRiskMapWidget) == 0xC8, "TNTRiskMapWidget size isn't 0xC8.");
	static_assert(sizeof(TNTRiskMapWidget) <= 0xC8, "TNTRiskMapWidget size is upper than 0xC8.");
	static_assert(sizeof(TNTRiskMapWidget) >= 0xC8, "TNTRiskMapWidget size is lower than 0xC8.");
#pragma pack(pop)
}