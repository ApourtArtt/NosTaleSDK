module;
#include <stdint.h>
export module TNTCuttonEffect;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCuttonEffect : public TEWControlWidgetEX
	{
		int32_t unknown12;		// 0x68
		uint8_t opacity;		// 0x6C
		bool isActive;			// 0x6D
		char unknown13;			// 0x6E probably padding (no W/R)
		char unknown14;			// 0x6F probably padding (no W/R)
		int32_t unknown15;		// 0x70 is being compared to unknown12 but with some extra comparison
		int unknown16;			// 0x74 unknown
	};
	static_assert(sizeof(TNTCuttonEffect) == 0x78, "TNTCuttonEffect does not have a size of 0x78.");
#pragma pack(pop)
}