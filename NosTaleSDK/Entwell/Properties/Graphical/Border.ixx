module;
#include <stdint.h>
export module Border;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct Border
	{
		int16_t topLeftX;	// 0x000
		int16_t topLeftY;	// 0x002
		int16_t botRightX;  // 0x004
		int16_t botRightY;	// 0x006
	};
	static_assert(sizeof(Border) == 0x8, "Border size isn't 0x8.");
	static_assert(sizeof(Border) <= 0x8, "Border size is upper than 0x8.");
	static_assert(sizeof(Border) >= 0x8, "Border size is lower than 0x8.");
#pragma pack(pop)
}