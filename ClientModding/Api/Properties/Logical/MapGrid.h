#pragma once
#include "../../Enums/CellType.h"

/**
 * @brief Game map grid representation.
 */
class MapGrid
{
public:
	short getWidth() const { return width; }
	short getHeight() const { return height; }

	CellType getCellType(short x, short y)
	{
		if (x < 0 || x > width) [[unlikely]] return CellType{};
		if (y < 0 || y > height) [[unlikely]] return CellType{};
		//return cells[x * width + height]; // It crashes btw
		return *(CellType*)((uintptr_t)&cells + x * width + y);
	}

	void setCellType(short x, short y, CellType cellType)
	{
		if (x < 0 || x > width) [[unlikely]] return;
		if (y < 0 || y > height) [[unlikely]] return;
		//cells[x * width + height] = cellType; // It crashes btw
		*(CellType*)((uintptr_t)&cells + x * width + y) = cellType;
	}

private:
	short width;
	short height;
	CellType* cells;
};
