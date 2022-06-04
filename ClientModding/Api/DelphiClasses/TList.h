#pragma once
#include <stdlib.h>
#pragma pack(push, 1)

template<class T>
class TList : public TObject
{
public:
	TList()
		: TList(1)
	{}

	TList(int32_t _capacity)
		: TObject(ClassSearcher::GetClassInfoFromName("TList").GetVTable())
		, length(0)
		, capacity(_capacity)
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
		// Should I free, or set value to nullptr at items[size] ?
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

	int32_t size() const
	{
		return length;
	}

	T get_item_at_index(int index)
	{
		if (index >= length || index < 0)
			return nullptr;
		return items[index];
	}

	T* items;				// 0x04
private:
	int32_t length;			// 0x08
	int32_t capacity;		// 0x0c
};
static_assert(sizeof(TList<int32_t>) == 0x10, "TList does not have a size of 0x10.");

#pragma pack(pop)
