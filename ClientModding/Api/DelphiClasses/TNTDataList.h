#pragma once
#include "TList.h"
#pragma pack(push, 1)

template<class T>
class TNTDataList : public TList<T>
{

};
static_assert(sizeof(TNTDataList<int32_t>) == 0x10, "TNTDataList does not have a size of 0x10.");

#pragma pack(pop)
