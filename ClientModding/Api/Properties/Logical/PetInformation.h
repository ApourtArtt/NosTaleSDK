#pragma once
#include <iostream>
#pragma pack(push, 1)

/**
 * @brief Game data representation of the pet information.
 */
class PetInformation
{
public:
	int32_t arrayPosition; //0x0000
	int32_t entityType; //0x0004
	int32_t id; //0x0008
	int32_t level; //0x000C
	int32_t loyalty; //0x0010
	char pad_0014[8]; //0x0014
	int32_t attackLevel; //0x001C
	int32_t minBaseAttack; //0x0020
	int32_t maxBaseAttack; //0x0024
	int32_t accuracy; //0x0028
	int32_t criticalChance; //0x002C
	int32_t criticalDamage; //0x0030
	int32_t defenseLevel; //0x0034
	int32_t meleeDefense; //0x0038
	int32_t meleeDodge; //0x003C
	int32_t rangeDefense; //0x0040
	int32_t rangeDodge; //0x0044
	int32_t magicDefense; //0x0048
	int32_t elementType; //0x004C 0 = no element, 1 = fire, 2 = water, 3 = light, 4 = shadow
	int32_t fireResistance; //0x0050
	int32_t waterResistance; //0x0054
	int32_t lightResistance; //0x0058
	int32_t shadowResistance; //0x005C
	int32_t currentHP; //0x0060
	int32_t maxHP; //0x0064
	int32_t currentMP; //0x0068
	int32_t maxMP; //0x006C
	int32_t isFollowing; //0x0070
	char pad_0074[5]; //0x0074
	int8_t nameSize; //0x0079
	char name[6]; //0x007A
	char pad_0080[40]; //0x0080
}; //Size: 0x00A8
static_assert(sizeof(PetInformation) == 0xA8, "PetInformation does not have a size of 0xA8");

#pragma pack(pop) 