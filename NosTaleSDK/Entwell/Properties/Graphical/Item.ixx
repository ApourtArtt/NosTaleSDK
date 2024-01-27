module;
#include <stdint.h>
export module Item;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct Item
	{
		int32_t skillVnum; // 0x00
		int16_t level; // 0x04
		int16_t unknown2; // 0x06 Probably padding
		int16_t heroLevel; // 0x08
		int16_t unknown4; //0x0A Probably padding
		int32_t unknown5; // 0x0C
		int32_t unknown6; // 0x10
		char* text; // 0x14 C str
		int32_t unknown7; // 0x18
		int16_t unknown8; // 0x1C 1 = tatoo ; 2 = skill ; 3 = item
		int16_t unknown8_2; // 0x1E
		int32_t unknown9; // 0x20
		int32_t unknown10; // 0x24
		int32_t unknown11; // 0x28
		int32_t unknown12; // 0x2C
		int16_t vnum;		// 0x30
		int16_t unknown13; // 0x32
		char* name; // 0x34 Note: not a delphi string
		char* itemName; // 0x38 Note: not a delphi string
		int32_t unknown15; // 0x3C
		int32_t unknown16; // 0x40
		int16_t unknown17; // 0x44
		int16_t imageId; // 0x46
		int32_t type; // 0x48
		char unknown18[0x55 - 0x4C]; // 0x4C
		bool isHero; //0x55
		char unknown19[0x5A - 0x56];
		int32_t itemType; // 0x5A
		//char unknown[0x28C - 0x4C]; // 0x4C
		//uint32_t tattooUpgrade; // 0x28C
		// All those variables seems to be NSgtdData.NOS > Item.dat
	};
	static_assert(sizeof(Item) == 0x5E, "Item does not have a size of 0x5E.");
#pragma pack(pop)
}