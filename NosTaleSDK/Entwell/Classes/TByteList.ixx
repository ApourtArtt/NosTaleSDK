module;
#include <stdint.h>
export module TByteList;
import TBaseList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TByteList : public TBaseList<uint8_t>
	{
		char unknown2[4];	// 0x20
	};
	static_assert(sizeof(TByteList) == 0x24, "TByteList does not have a size of 0x24.");
#pragma pack(pop)
}