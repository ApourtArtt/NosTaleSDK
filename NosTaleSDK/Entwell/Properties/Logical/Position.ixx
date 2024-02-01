module;
#include <stdint.h>
export module Position;

namespace NosTaleSDK::Entwell::Properties::Logical
{
#pragma pack(push, 1)
	export struct Position
	{
		int16_t x;
		int16_t y;
	};
	static_assert(sizeof(Position) == 0x4, "Position size isn't 0x4.");
	static_assert(sizeof(Position) <= 0x4, "Position size is upper than 0x4.");
	static_assert(sizeof(Position) >= 0x4, "Position size is lower than 0x4.");
#pragma pack(pop)
}