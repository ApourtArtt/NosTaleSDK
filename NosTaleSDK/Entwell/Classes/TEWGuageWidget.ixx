module;
#include <stdint.h>
export module TEWGuageWidget;
import TEWMoveWidget;
import DelphiString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWGuageWidget : public TEWMoveWidget
	{
		uint32_t unknown23;							// 0x080
		float unknown24;							// 0x084
		float unknown25;							// 0x088
		float unknown26;							// 0x08C
		uint16_t unknown27;							// 0x090
		uint16_t unknown28;							// 0x092
		void* unknown29;							// 0x094 TNTRaidPersoInfo_Fourty maybe Callback
		uint32_t unknown30;							// 0x098
		uint32_t unknown31;							// 0x09C
		uint8_t unknown32;							// 0x0A0
		uint8_t unknown33;							// 0x0A1
		char unknown34[10];							// 0x0A2
		uint32_t unknown35;							// 0x0AC TEWStats
		char unknown36[4];							// 0x0B0
		Properties::Logical::DelphiWString* unknown37;	// 0x0B4
		uint8_t unknown38;							// 0x0B8
		char unknown39[3];							// 0x0B9
	};
	static_assert(sizeof(TEWGuageWidget) == 0xBC, "TEWGuageWidget size isn't 0xBC.");
	static_assert(sizeof(TEWGuageWidget) <= 0xBC, "TEWGuageWidget size is upper than 0xBC.");
	static_assert(sizeof(TEWGuageWidget) >= 0xBC, "TEWGuageWidget size is lower than 0xBC.");
#pragma pack(pop)
}