module;
#include <stdint.h>
export module Icon;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct Icon
	{
		int32_t unknown1; // 0x00
		int16_t unknown2; // 0x04
		int16_t unknown3; // 0x06
		struct Item* itemProp; // 0x08
		int16_t imageId; // 0x0c
		int16_t colorStyle; // 0x0e special color for 0x1 to 0xf - other is "normal" (bgra(255, 255, 255, 255)
		int8_t displayType; // 0x10 from 0 to 7 - 0=nothing 1/2=item with quantity 3=stuff?... //5
		// Upgrade somewhere in the following bytes (below, somewhere)
		char unknown8[3]; // 0x11
		int32_t unknown4; // 0x14
		int32_t unknown5; // 0x18
		uint16_t inventoryType; // 0x1C
		uint16_t slot;		// 0x1E
		uint16_t amount;	// 0x20
		int8_t rarity;		// 0x22
		int8_t upgrade;		// 0x23
		int8_t perfection;	// 0x24 cooldown (int32_t) for other
		char unknown9[3];	// 0x25
		int32_t unknown10;	// 0x28
		int32_t unknown11;	// 0x2C
		int32_t unknown12;	// 0x30
		int32_t unknown13;	// 0x34
		int32_t carveRunes; // 0x38
		int32_t unknown14;	// 0x3C
		int32_t unknown15;	// 0x40
		int32_t unknown16;	// 0x44
	};
	static_assert(sizeof(Icon) == 0x48, "Icon does not have a size of 0x48.");
#pragma pack(pop)
}