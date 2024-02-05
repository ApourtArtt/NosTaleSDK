module;
#include <stdint.h>
export module TEWTextOutLabel;
import TEWTextOut;
import DelphiString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWTextOutLabel : public TEWTextOut
	{
		Properties::Logical::DelphiWString* text;// 0x078
		uint8_t unknown27;						// 0x07C
		char unknown28[3];						// 0x07D
		uint32_t unknown29;						// 0x080
		uint32_t unknown30;						// 0x084	
		uint8_t unknown31;						// 0x088	
		char unknown32[3];						// 0x089	
	};
	static_assert(sizeof(TEWTextOutLabel) == 0x8C, "TEWTextOutLabel size isn't 0x8C.");
	static_assert(sizeof(TEWTextOutLabel) <= 0x8C, "TEWTextOutLabel size is upper than 0x8C.");
	static_assert(sizeof(TEWTextOutLabel) >= 0x8C, "TEWTextOutLabel size is lower than 0x8C.");
#pragma pack(pop)
}