#pragma once
#include "TNTIntHeadList.h"
#include <stdint.h>
#pragma pack(push, 1)

/*
This struct does not seem to add anything more than TNTIntHeadList, so it's probably
the element stored that changes, but since it is only inherited by TNTCItemDataList,
it is not needed to dig deeper for now.
*/
template<class T>
class TNTNonMemIntHeadList : public TNTIntHeadList<T>
{
public:
	TNTNonMemIntHeadList() : TNTIntHeadList<T>() {}
	TNTNonMemIntHeadList(uint32_t Capacity) : TNTIntHeadList<T>(Capacity) {}
};
static_assert(sizeof(TNTNonMemIntHeadList<void*>) == 0x10, "TNTNonMemIntHeadList does not have a size of 0x10.");

#pragma pack(pop)
