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
		T* items;				// 0x04
		int32_t length;		// 0x08
		uint32_t capacity;		// 0x0c
	};
	static_assert(sizeof(TList<int32_t>) == 0x10, "TList does not have a size of 0x10.");
#pragma pack(pop)
}