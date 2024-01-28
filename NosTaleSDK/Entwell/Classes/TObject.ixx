module;
#include <stdint.h>
export module TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TObject
	{
		uintptr_t vTable; // 0x00
	};
	static_assert(sizeof(TObject) == 0x04, "TObject does not have a size of 0x04.");
#pragma pack(pop)
}