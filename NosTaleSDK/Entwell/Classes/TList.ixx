module;
#include <cstdint>
export module TList;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TList : public TObject
	{
		T* items;			// 0x004
		int32_t length;		// 0x008
		uint32_t capacity;	// 0x00C
	};
	static_assert(sizeof(TList<void*>) == 0x10, "TList size isn't 0x10.");
	static_assert(sizeof(TList<void*>) <= 0x10, "TList size is upper than 0x10.");
	static_assert(sizeof(TList<void*>) >= 0x10, "TList size is lower than 0x10.");
#pragma pack(pop)
}