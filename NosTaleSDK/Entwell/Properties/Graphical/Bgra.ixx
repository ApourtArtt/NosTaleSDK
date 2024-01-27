module;
#include <stdint.h>
export module Bgra;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct Bgra
	{
		uint8_t blue;
		uint8_t green;
		uint8_t red;
		uint8_t alpha;
	};
	static_assert(sizeof(Bgra) == 0x4, "Bgra does not have a size of 0x4.");
#pragma pack(pop)
}