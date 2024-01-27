module;
#include <stdint.h>
export module TEWTextOutLabel;
import TEWTextOut;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWTextOutLabel : public TEWTextOut
	{
		char* text;
		char unknown17[16];
	};
	static_assert(sizeof(TEWTextOutLabel) == 0x8C, "TEWTextOutLabel does not have a size of 0x8C.");
#pragma pack(pop)
}