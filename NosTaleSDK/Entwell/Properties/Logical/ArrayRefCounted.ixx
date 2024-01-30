module;
#include <stdint.h>
#include <vector>
export module ArrayRefCounted;

namespace NosTaleSDK::Entwell::Properties::Logical
{
#pragma pack(push, 1)
	template<typename T>
	struct ArrayRefCounted
	{
		int32_t ref;
		std::vector<T> data;
	};
	static_assert(sizeof(ArrayRefCounted<void*>) == 0x14, "ArrayRefCounted size isn't 0x14.");
	static_assert(sizeof(ArrayRefCounted<void*>) <= 0x14, "ArrayRefCounted size is upper than 0x14.");
	static_assert(sizeof(ArrayRefCounted<void*>) >= 0x14, "ArrayRefCounted size is lower than 0x14.");
#pragma pack(pop)
}