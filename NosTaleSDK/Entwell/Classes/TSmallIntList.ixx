module;
#include <stdint.h>
export module TSmallIntList;
import TBaseList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TSmallIntList : public TBaseList<short>
	{
		uint32_t unknown9;	// 0x020
	};
	static_assert(sizeof(TSmallIntList) == 0x24, "TSmallIntList size isn't 0x24.");
	static_assert(sizeof(TSmallIntList) <= 0x24, "TSmallIntList size is upper than 0x24.");
	static_assert(sizeof(TSmallIntList) >= 0x24, "TSmallIntList size is lower than 0x24.");
#pragma pack(pop)
}