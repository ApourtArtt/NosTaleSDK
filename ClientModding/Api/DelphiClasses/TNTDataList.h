#pragma once
#include "TList.h"
#pragma pack(push, 1)

template<class T>
class TNTDataList : public TList<T>
{
public:
	TNTDataList() : TList<T>() {}
	TNTDataList(uint32_t Capacity) : TList<T>(Capacity) {}
};
static_assert(sizeof(TNTDataList<void*>) == 0x10, "TNTDataList does not have a size of 0x10.");

#pragma pack(pop)
