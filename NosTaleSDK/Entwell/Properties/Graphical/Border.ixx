module;
#include <stdint.h>
export module Border;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct Border
	{
		int16_t topLeftX;
		int16_t topLeftY;
		int16_t botRightX;
		int16_t botRightY;
	};
	static_assert(sizeof(Border) == 0x8, "Border does not have a size of 0x8.");
#pragma pack(pop)
}