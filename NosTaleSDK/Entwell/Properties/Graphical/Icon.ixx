module;
#include <stdint.h>
export module Icon;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct Icon
	{
		int32_t unknown1;		// 0x000
		int16_t unknown2;		// 0x004
		int16_t unknown3;		// 0x006
		struct Item* itemProp;	// 0x008
		int16_t imageId;		// 0x00c
		int16_t colorStyle;		// 0x00e special color for 0x1 to 0xf - other is "normal" (bgra(255, 255, 255, 255)
		int8_t displayType;		// 0x010 from 0 to 7 - 0=nothing 1/2=item with quantity 3=stuff?... //5
		char unknown8[3];		// 0x011
		int32_t unknown4;		// 0x014
		int32_t unknown5;		// 0x018
		uint16_t inventoryType; // 0x01C
		uint16_t slot;			// 0x01E
		uint16_t amount;		// 0x020
		int8_t rarity;			// 0x022
		int8_t upgrade;			// 0x023
		int8_t perfection;		// 0x024 cooldown (int32_t) for other
		char unknown9[3];		// 0x025
		int32_t unknown10;		// 0x028
		int32_t unknown11;		// 0x02C
		int32_t unknown12;		// 0x030
		int32_t unknown13;		// 0x034
		int32_t carveRunes;		// 0x038
		int32_t unknown14;		// 0x03C
		int32_t unknown15;		// 0x040
		int32_t unknown16;		// 0x044
	};
	static_assert(sizeof(Icon) == 0x48, "Icon size isn't 0x48.");
	static_assert(sizeof(Icon) <= 0x48, "Icon size is upper than 0x48.");
	static_assert(sizeof(Icon) >= 0x48, "Icon size is lower than 0x48.");
#pragma pack(pop)
}