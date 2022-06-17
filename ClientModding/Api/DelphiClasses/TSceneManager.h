#pragma once
#include "TObject.h"
#include "TLBSCamera.h"
#include "../Properties/Logical/MapGrid.h"
#include "../../MemoryHelper/PatternScan.h"
#include "../../Utils/Logger.h"
#pragma pack(push, 1)

/**
 * @brief Representation of the game TSceneManager structure.
 */
class TSceneManager : public TObject
{
public:
	[[nodiscard]] MapGrid* getMapGrid() { return mapGrid; }
	[[nodiscard]] TLBSCamera* getCamera() { return camera; }

	[[nodiscard]] static TSceneManager* getNtInstance()
	{
		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			auto _ = Logger::PushPopModuleName("TSceneManager");

			patternAddr = PatternScan(
				"\xA1\x00\x00\x00\x00\x00\x00\x00\x00\x58\x00\x0F\x84\xBF",
				"x????????xxxxx", 1
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
		return ***(TSceneManager****)patternAddr;
	}

private:
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
	TLBSCamera* camera; //0x006C
	char pad_0070[48]; //0x0070
};
static_assert(sizeof(TSceneManager) == 0xA0, "TSceneManager does not have a size of 0xA0");

#pragma pack(pop)
