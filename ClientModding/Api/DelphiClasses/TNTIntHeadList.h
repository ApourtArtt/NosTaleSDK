#pragma once
#include "TNTDataList.h"
#include <stdint.h>
#pragma pack(push, 1)

template<class T>
class IntListElement
{
public:
	[[nodiscard]] int32_t getVnum() noexcept { return vnum; }
	[[nodiscard]] T getValue() noexcept { return value; }

protected:
	int32_t vnum;
	T value;
};

template<class T>
class TNTIntHeadList : public TNTDataList<IntListElement<T>*>
{
public:
	TNTIntHeadList() : TNTDataList<T>() {}
	TNTIntHeadList(uint32_t Capacity) : TNTDataList<T>(Capacity) {}
};
static_assert(sizeof(TNTIntHeadList<void*>) == 0x10, "TNTIntHeadList does not have a size of 0x10.");

#pragma pack(pop)
