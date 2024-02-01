module;
#include <stdint.h>
export module TNTItemList;
import TNTDataList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTItemList : public TNTDataList<struct Item>
	{
		uint8_t unknown;	// 0x010
		char unknown2[3];	// 0x011
		uint32_t unknown3;	// 0x014
	};
	static_assert(sizeof(TNTItemList) == 0x18, "TNTItemList size isn't 0x18.");
	static_assert(sizeof(TNTItemList) <= 0x18, "TNTItemList size is upper than 0x18.");
	static_assert(sizeof(TNTItemList) >= 0x18, "TNTItemList size is lower than 0x18.");
#pragma pack(pop)
}