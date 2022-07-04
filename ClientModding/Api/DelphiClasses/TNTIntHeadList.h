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
	TNTIntHeadList() : TNTDataList<IntListElement<T>*>() {}
	TNTIntHeadList(uint32_t Capacity) : TNTDataList<IntListElement<T>*>(Capacity) {}

	[[nodiscard]] IntListElement<T>* find(int32_t vnum)
	{
		for (auto i = 0; i < this->length; i++)
		{
			IntListElement<T>* item = this->items[i];
			if (item == nullptr)
			{
				Logger::Error("[TNTIntHeadList] items[%d] is nullptr", i);
				continue;
			}
			if (item->getVnum() == vnum)
				return item;
		}
		return nullptr;
	}
};
static_assert(sizeof(TNTIntHeadList<IntListElement<void*>*>) == 0x10, "TNTIntHeadList does not have a size of 0x10.");

#pragma pack(pop)
