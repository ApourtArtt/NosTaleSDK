#pragma once
#include <stdint.h>
#include "ClassSearcher.h"
#pragma pack(push, 1)

/**
 * @brief Representation of the game TObject structure.
 */
class TObject
{
public:
	TObject()
		: vTable(ClassSearcher::GetClassInfoFromName("TObject").GetVTable())
	{}

	TObject(int32_t vTableAddy)
		: vTable(vTableAddy)
	{}

	int32_t getVTable() const { return vTable; }

protected:
	int32_t vTable; // 0x00 Define the widget type
};
static_assert(sizeof(TObject) == 0x04, "TObject does not have a size of 0x04.");

#pragma pack(pop)