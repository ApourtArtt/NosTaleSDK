#pragma once
#include "TObject.h"
#pragma pack(push, 1)

template<class T>
class TList : public TObject
{
public:
	TList()
		: TList(1)
	{}

	TList(uint32_t Capacity)
		: TObject(ClassSearcher::GetClassInfoFromName("TList").GetVTable())
		, length(0)
		, capacity(Capacity)
	{
		items = (T*)malloc(capacity * sizeof(T));
	}

	void push_back(T item)
	{
		if (capacity <= length)
			reserve();
		items[length] = item;
		length += 1;
	}

	void pop_back()
	{
		if (length <= 0) return;

		length -= 1;
		// Should be freed if only used by this project but since that's not guaranteed, let's keep it as a memory leek.
	}

	void reserve()
	{
		capacity *= 2;

		T* newItems = (T*)malloc(capacity * sizeof(T));

		for (int i = 0; i < length; i++)
		{
			newItems[i] = items[i];
		}

		items = newItems;
	}

	uint32_t size() const
	{
		return length;
	}

	T getItem(int index)
	{
		if (index >= length || index < 0)
			return nullptr;
		return items[index];
	}

	T* getItems() { return items; }

protected:
	T* items;				// 0x04
	uint32_t length;		// 0x08
	uint32_t capacity;		// 0x0c
};
static_assert(sizeof(TList<int32_t>) == 0x10, "TList does not have a size of 0x10.");

#pragma pack(pop)
