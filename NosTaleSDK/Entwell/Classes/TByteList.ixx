module;
#include <stdint.h>
export module TByteList;
import TBaseList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TByteList : public TBaseList<uint8_t>
	{
		uint32_t unknown9;	// 0x020
	};
	static_assert(sizeof(TByteList) == 0x24, "TByteList size isn't 0x24.");
	static_assert(sizeof(TByteList) <= 0x24, "TByteList size is upper than 0x24.");
	static_assert(sizeof(TByteList) >= 0x24, "TByteList size is lower than 0x24.");
#pragma pack(pop)
}