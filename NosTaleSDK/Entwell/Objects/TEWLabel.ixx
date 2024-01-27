module;
#include <stdint.h>
export module TEWLabel;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWLabel : public TEWControlWidgetEX
	{
		char unknown14;				// 0x68 avoid parent from displaying on 0
		char unknown15;				// 0x69 avoid TEWLabel from displaying itself on != 0
		char textStyle[0x0B];		// 0x6A
		char unknown16[3];			// 0x75
		char textPosition[0x10];	// 0x78
		char unknown17[8];			// 0x88
	};
	static_assert(sizeof(TEWLabel) == 0x90, "TEWLabel does not have a size of 0x90.");
#pragma pack(pop)
}
