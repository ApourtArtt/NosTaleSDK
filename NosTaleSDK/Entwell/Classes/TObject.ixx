module;
#include <stdint.h>
export module TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TObject
	{
		uintptr_t vTable; // 0x000
	};
	static_assert(sizeof(TObject) == 0x4, "TObject size isn't 0x4.");
	static_assert(sizeof(TObject) <= 0x4, "TObject size is upper than 0x4.");
	static_assert(sizeof(TObject) >= 0x4, "TObject size is lower than 0x4.");
#pragma pack(pop)
}