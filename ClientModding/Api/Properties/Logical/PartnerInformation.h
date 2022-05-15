#pragma once
#pragma pack(push, 1)

/**
 * @brief Game data representation of the partner information.
 */
class PartnerInformation
{
public:
	int32_t arrayPosition; //0x0000
	int32_t entityType; //0x0004
	int32_t id; //0x0008
	int32_t level; //0x000C
	int32_t privacy; //0x0010
	char pad_0014[20]; //0x0014
	int32_t attackType; //0x0028 0 = melee, 1 = range, 2 = magic
	int32_t attackLevel; //0x002C
	int32_t minBaseAttack; //0x0030
	int32_t maxBaseAttack; //0x0034
	int32_t accuracy; //0x0038
	int32_t criticalChance; //0x003C
	int32_t criticalDamage; //0x0040
	int32_t defenseLevel; //0x0044
	int32_t meleeDefense; //0x0048
	int32_t meleeDodge; //0x004C
	int32_t rangeDefense; //0x0050
	int32_t rangeDodge; //0x0054
	int32_t magicDefense; //0x0058
	int32_t elementType; //0x005C
	int32_t fireResistance; //0x0060
	int32_t waterResistance; //0x0064
	int32_t LightResistance; //0x0068
	int32_t ShadowResistance; //0x006C
	int32_t currentHP; //0x0070
	int32_t maxHP; //0x0074
	int32_t currentMP; //0x0078
	int32_t maxMP; //0x007C
	int32_t isFollowing; //0x0080
	char pad_0084[4]; //0x0084
	int8_t nameLength; //0x0088
	char N00002058[6]; //0x0089
	char pad_008F[64]; //0x008F
}; //Size: 0x00CF
static_assert(sizeof(PartnerInformation) == 0xCF, "PartnerInformation does not have a size of 0xCF");

#pragma pack(pop) 