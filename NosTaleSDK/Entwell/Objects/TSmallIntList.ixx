module;
#include <stdint.h>
export module TSmallIntList;
import TBaseList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TSmallIntList : public TBaseList<int32_t>
	{
		char unknown2[4];	// 0x20
	};
	static_assert(sizeof(TSmallIntList) == 0x24, "TSmallIntList does not have a size of 0x24.");
#pragma pack(pop)
}