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
	static_assert(sizeof(ArrayRefCounted<void*>) == 0x14, "ArrayRefCounted does not have a size of 0x14.");
#pragma pack(pop)
}