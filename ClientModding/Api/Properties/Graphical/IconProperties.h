#pragma once
#pragma pack(push, 1)
#include <stdint.h>

// TODO: Add documentation

class ItemDataProperties
{

};

class IconProperties
{
public:
	IconProperties(int16_t Vnum)
		: vnum(Vnum)
	{}

private:
	char unknown1[4];		// 0x00
	char unknown2[4];		// 0x04
	char unknown3[4];		// 0x08 name, etc, it's a structure
	/* Unknown3 :
	int32_t vnum1 // This one seems useless
	char unknown1[12*4]
	int32_t vnum2
	char unknown2[4];
	char* name; // not a NtString, and it's not unicode, it's like a char*.
	bool unavailable;
	bool sellingImpossible;
	bool dropImpossible;
	bool tradeImpossible;
	char unknown3[4];
	in32_t imageId;
	char unknown4[20];
	char unknown5[2];
	unsigned char allowedClass; 0: none 1: adven 2: swordsman 4: archer 8: magician 16: feast. Bit flag
	so many more data
	*/
	int16_t vnum;			// 0x0C
	char unknown4[2];		// 0x0E
	char type;				// 0x10
	/*
	0: None
	1: Etc
	2: Main
	3: Equip
	4: ?
	5: ?
	6: Something with shell or enhancement
	7: Fish
	*/
	char edgesGreenOrRed;	// 0x11
	char unknown5[2];		// 0x12 Maybe just padding ?
	char unknown6[12];		// 0x14
	int16_t quantity;		// 0x20
	char rarity;			// 0x22
	uint8_t upgrade;		// 0x23
};
static_assert(sizeof(IconProperties) == 0x24, "IconProperties does not have a size of 0x24.");

#pragma pack(pop)