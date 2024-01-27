module;
#include <vector>
export module Array;

namespace NosTaleSDK::Entwell::Properties::Logical
{
#pragma pack(push, 1)
	template<typename T>
	struct Array
	{
		std::vector<T> data;
	};
	static_assert(sizeof(Array<void*>) == 0x10, "Array does not have a size of 0x10.");
#pragma pack(pop)
}