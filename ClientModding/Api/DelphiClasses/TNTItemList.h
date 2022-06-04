#pragma once
#include "TNTDataList.h"
#pragma pack(push, 1)

// TODO: Find uknown values (probably 2 integers)

template<class T>
class TNTItemList : public TNTDataList<T>
{

protected:
	char uknown[8];
};
static_assert(sizeof(TNTItemList<int32_t>) == 0x18, "TNTItemList does not have a size of 0x18.");

#pragma pack(pop)
