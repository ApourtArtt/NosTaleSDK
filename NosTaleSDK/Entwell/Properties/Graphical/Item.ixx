module;
#include <stdint.h>
export module Item;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct Item
	{
		int32_t skillVnum;				// 0x000
		int16_t level;					// 0x004
		int16_t unknown2;				// 0x006
		int16_t heroLevel;				// 0x008
		int16_t unknown4;				// 0x00A
		int32_t unknown5;				// 0x00C
		int32_t unknown6;				// 0x010
		char* text;						// 0x014 C str
		int32_t unknown7;				// 0x018
		int16_t unknown8;				// 0x01C 1 = tatoo ; 2 = skill ; 3 = item
		int16_t unknown8_2;				// 0x01E
		int32_t unknown9;				// 0x020
		int32_t unknown10;				// 0x024
		int32_t unknown11;				// 0x028
		int32_t unknown12;				// 0x02C
		int16_t vnum;					// 0x030
		int16_t unknown13;				// 0x032
		char* name;						// 0x034 Note: not a delphi string
		char* itemName;					// 0x038 Note: not a delphi string
		int32_t unknown15;				// 0x03C
		int32_t unknown16;				// 0x040
		int16_t unknown17;				// 0x044
		int16_t imageId;				// 0x046
		int32_t type;					// 0x048
		char unknown18[0x55 - 0x4C];	// 0x04C
		bool isHero;					// 0x055
		char unknown19[0x5A - 0x56];	// 0x056
		int32_t itemType;				// 0x05A

		// All those variables seems to be NSgtdData.NOS > Item.dat
	};
	static_assert(sizeof(Item) == 0x5E, "Item size isn't 0x5E.");
	static_assert(sizeof(Item) <= 0x5E, "Item size is upper than 0x5E.");
	static_assert(sizeof(Item) >= 0x5E, "Item size is lower than 0x5E.");
#pragma pack(pop)
}