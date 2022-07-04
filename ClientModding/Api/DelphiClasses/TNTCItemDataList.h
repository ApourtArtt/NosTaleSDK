#pragma once
#include "TNTNonMemIntHeadList.h"
#include "../../MemoryHelper/PatternScan.h"
#include "../Properties/Graphical/IconProperties.h"
#pragma pack(push, 1)

class TNTCItemDataList : public TNTNonMemIntHeadList<ItemDataProperties>
{
public:
	TNTCItemDataList() : TNTNonMemIntHeadList<ItemDataProperties>() {}
	TNTCItemDataList(uint32_t Capacity) : TNTNonMemIntHeadList<ItemDataProperties>(Capacity) {}

	[[nodiscard]] static TNTCItemDataList* getNtInstance() noexcept
	{
		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			auto _ = Logger::PushPopModuleName("TNTCItemDataList");

			patternAddr = PatternScan(
				"\xe8\x00\x00\x00\x00\x8b\x55\xa0\x58\xe8\x00\x00\x00\x00\x75\x00\xa1\x00\x00\x00\x00\x8b\x10\xff\x52\x08\x8b\xd7\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00",
				"x????xxxxx????x?x????xxxxxxxx????x????", 17
			);
			if (patternAddr == nullptr)
			{
				Logger::Error("Failed scanning pattern");
				return nullptr;
			}
			Logger::Log("patternAddr = %x", patternAddr);

			Logger::Success("Successfully initialized");
		}

		// Note: if it gets delete-d and new-ed, a refresh of the dereferenced address will be required.
		// Since I don't know if this object ever gets deleted (I HIGHLY doubt it), I am not handling it.
		return **(TNTCItemDataList***)patternAddr;
	}
};
static_assert(sizeof(TNTCItemDataList) == 0x10, "TNTCItemDataList does not have a size of 0x10.");

#pragma pack(pop)
