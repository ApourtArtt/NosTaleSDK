#pragma once
#include <stdint.h>

enum class CellType : int8_t
{
	NOT_WALKABLE = 1,
	CAN_HIT_THROUGH = 2,
};

inline CellType operator|(CellType a, CellType b)
{
	return static_cast<CellType>(static_cast<int8_t>(a) | static_cast<int8_t>(b));
}