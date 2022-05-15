#pragma once
#include "TObject.h"
#include "../Properties/Logical/MapGrid.h"

/**
 * @brief Representation of the game TSceneManager structure.
 */
class TSceneManager : public TObject
{
public:
	uint32_t playerListPtr; //0x0004
	uint32_t monsterListPtr; //0x0008
	uint32_t npcListPtr; //0x000C
	uint32_t itemListPtr; //0x0010
	uint32_t unknownPtr1; // 0x0014
	uint32_t unknownPtr2; // 0x0018
	uint32_t unknownPtr3; // 0x001C
	MapGrid* mapGrid; // 0x0020
	char pad_0014[8]; //0x0024
	int32_t playerID; //0x002C
	uint32_t mapPlayerObjPtr; //0x0030
	char pad_0034[32]; //0x0034
	int16_t targetSkillX; //0x0054
	int16_t targetSkillY; //0x0056
	char pad_0058[20]; //0x0058
	class TLBSCamera* TLBSCameraPtr; //0x006C
	char pad_0070[48]; //0x0070
}; //Size: 0x00A0
static_assert(sizeof(TSceneManager) == 0xA0, "TSceneManager does not have a size of 0xA0");