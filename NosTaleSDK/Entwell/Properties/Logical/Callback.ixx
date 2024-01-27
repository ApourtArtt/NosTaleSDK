module;
#include <stdint.h>
export module Callback;

namespace NosTaleSDK::Entwell::Properties::Logical
{
#pragma pack(push, 1)
	export struct Callback
	{
		int32_t function;
		int32_t arg;
	};
	static_assert(sizeof(Callback) == 0x8, "Callback does not have a size of 0x8.");
#pragma pack(pop)
}