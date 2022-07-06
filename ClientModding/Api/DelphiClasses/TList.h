#pragma once
#include "TObject.h"
#pragma pack(push, 1)

// Note: There are plenty of memory leaks - DO NOT fix it, most is handled by the client
// and we can not guarantee that the client won't try to access something freed.
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

	void push_front(T item)
	{
		insert(item, 0);
	}

	void insert(T item, uint32_t index)
	{
		length++;
		if (length >= capacity)
			capacity *= 2;

		T* newItems = (T*)malloc(capacity * sizeof(T));
		auto i = 0;

		for (; i < index && i < length; i++)
			newItems[i] = items[i];

		newItems[i] = item;

		for (; i < length; i++)
			newItems[i + 1] = items[i];

		items = newItems;
	}

	void pop_back()
	{
		if (length <= 0) return;

		length -= 1;
	}

	void reserve()
	{
		capacity *= 2;

		T* newItems = (T*)malloc(capacity * sizeof(T));

		for (auto i = 0; i < length; i++)
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
