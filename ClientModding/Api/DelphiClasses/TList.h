#pragma once
#include "TObject.h"
#pragma pack(push, 1)

// Note: There are plenty of memory leaks - DO NOT fix it, most of them are handled by the client
// and we can not guarantee that the client will not try to access something freed.
// That means the caller is responsible of managing the memory - if he wants to optimize (not needed most of the time tbh)
template<class T>
class TList : public TObject
{
public:
	[[nodiscard]] TList() noexcept
		: TList(1)
	{}

	[[nodiscard]] TList(uint32_t Capacity) noexcept
		: TObject(ClassSearcher::GetClassInfoFromName("TList").GetVTable())
		, length(0)
		, capacity(Capacity)
	{
		items = (T*)malloc(capacity * sizeof(T));
	}

	[[nodiscard]] TList(std::vector<T> Vec) noexcept
		: TList<T>(Vec.size())
	{
		for (auto i = 0; i < Vec.size(); i++)
			push_back(Vec[i]);
	}

	void push_back(T item) noexcept
	{
		if (capacity <= length)
			reserve();
		items[length] = item;
		length += 1;
	}

	void push_front(T item) noexcept
	{
		insert(item, 0);
	}

	void insert(T item, uint32_t index) noexcept
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

	void pop_back() noexcept
	{
		if (length <= 0) return;

		length -= 1;
	}

	void reserve() noexcept
	{
		capacity *= 2;

		T* newItems = (T*)malloc(capacity * sizeof(T));

		for (auto i = 0; i < length; i++)
			newItems[i] = items[i];

		items = newItems;
	}

	[[nodiscard]] uint32_t size() const noexcept
	{
		return length;
	}

	[[nodiscard]] T getItem(int index) noexcept
	{
		if (index >= length || index < 0)
			return NULL;
		return items[index];
	}

	[[nodiscard]] T* getItems() noexcept { return items; }

	[[nodiscard]] std::vector<T> toVector() noexcept
	{
		std::vector<T> vec(length);
		for (auto i = 0; i < length; i++)
			vec.push_back(items[i]);
		return vec;
	}

protected:
	T* items;				// 0x04
	uint32_t length;		// 0x08
	uint32_t capacity;		// 0x0c
};
static_assert(sizeof(TList<int32_t>) == 0x10, "TList does not have a size of 0x10.");

#pragma pack(pop)
