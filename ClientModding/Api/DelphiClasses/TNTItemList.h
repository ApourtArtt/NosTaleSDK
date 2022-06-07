#pragma once
#include "TNTDataList.h"
#pragma pack(push, 1)

// TODO: Find uknown values (probably 2 integers)

typedef void* Item; // I don't know the type, so void* for now

class TNTItemList : public TNTDataList<Item>
{

protected:
	char uknown[8];
};
static_assert(sizeof(TNTItemList) == 0x18, "TNTItemList does not have a size of 0x18.");

#pragma pack(pop)
