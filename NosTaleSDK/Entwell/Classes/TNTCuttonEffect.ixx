module;
#include <stdint.h>
export module TNTCuttonEffect;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCuttonEffect : public TEWControlWidgetEX
	{
		int32_t unknown20;		// 0x068
		uint8_t opacity;		// 0x06C
		bool isActive;			// 0x06D
		char unknown21[2];		// 0x06E
		uint32_t unknown22;		// 0x070
		uint32_t unknown23;		// 0x074
	};
	static_assert(sizeof(TNTCuttonEffect) == 0x78, "TNTCuttonEffect size isn't 0x78.");
	static_assert(sizeof(TNTCuttonEffect) <= 0x78, "TNTCuttonEffect size is upper than 0x78.");
	static_assert(sizeof(TNTCuttonEffect) >= 0x78, "TNTCuttonEffect size is lower than 0x78.");
#pragma pack(pop)
}