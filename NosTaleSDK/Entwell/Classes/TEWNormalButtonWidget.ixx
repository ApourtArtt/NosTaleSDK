module;
#include <stdint.h>
export module TEWNormalButtonWidget;
import TEWCustomButtonWidget;
import DelphiString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWNormalButtonWidget : public TEWCustomButtonWidget
	{
		uint32_t unknown35;							// 0x0D8
		uint32_t unknown36;							// 0x0DC
		uint8_t unknown37;							// 0x0E0
		uint8_t unknown38;							// 0x0E1
		uint8_t unknown39;							// 0x0E2
		uint8_t unknown40;							// 0x0E3
		uint32_t unknown41;							// 0x0E4
		char unknown42[8];							// 0x0E8
		void* unknown43;							// 0x0F0 TEWStats*
		char unknown44[4];							// 0x0F4
		Properties::Logical::DelphiWString* unknown45;	// 0x0F8
		uint8_t unknown46;							// 0x0FC
		char unknown47[3];							// 0x0FD
	};
	static_assert(sizeof(TEWNormalButtonWidget) == 0x100, "TEWNormalButtonWidget size isn't 0x100.");
	static_assert(sizeof(TEWNormalButtonWidget) <= 0x100, "TEWNormalButtonWidget size is upper than 0x100.");
	static_assert(sizeof(TEWNormalButtonWidget) >= 0x100, "TEWNormalButtonWidget size is lower than 0x100.");
#pragma pack(pop)
}
