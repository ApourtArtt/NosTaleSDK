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
	static_assert(sizeof(Callback) == 0x8, "ArrayRefCounted size isn't 0x8.");
	static_assert(sizeof(Callback) <= 0x8, "ArrayRefCounted size is upper than 0x8.");
	static_assert(sizeof(Callback) >= 0x8, "ArrayRefCounted size is lower than 0x8.");
#pragma pack(pop)
}