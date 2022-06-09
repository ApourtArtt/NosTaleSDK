#pragma once
#include "TObject.h"
#include "../../MemoryHelper/PatternScan.h"
#include "../../Utils/Logger.h"
#include "TMapPlayerObj.h"
#include "TList.h"
#pragma pack(push, 1)

class TPlayerObjManager : public TObject
{
public:
	[[nodiscard]] static TPlayerObjManager* getNtInstance()
	{
		auto _ = Logger::PushPopModuleName("TPlayerObjManager");

		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			patternAddr = PatternScan(
				"\x50\x6a\x00\x6a\x00\x6a\x00\x6a\x00\x6a\x00\x6a\x00\x33\xd2\x33\xc0\xe8\x00\x00\x00\x00\x8b\xd0\xa1\x00\x00\x00\x00",
				"xx?x?x?x?x?x?xxxxx????xxx????", 25);
			if (patternAddr == nullptr)
			{
				Logger::Error("Failed scanning pattern");
				return nullptr;
			}
			Logger::Log("patternAddr = %x", patternAddr);
		}

		Logger::Success("Successfully initialized");
		return ***(TPlayerObjManager****)patternAddr;
	}

	void setNpcTalkRange(int16_t Value) { npcTalkRange = Value; }

private:
	int16_t currentX; // 0x04
	int16_t currentY; // 0x06
	int16_t destX; // 0x08
	int16_t destY; // 0x0A
	int32_t lastAttackTimestamp; // 0x0C Not attacking but being on the way to increases it
	char unknown[4]; // 0x10
	int32_t state; // 0x14 1=picking up, 2=attacking, 3=second weapon, 4=walking to cast skill
	void* TByteList; //0x18 No vTable - not sure
	char unknown1[4]; // 0x1C did not find any use but it's not padding
	TMapPlayerObj* mapPlayerObj; //0x20
	int32_t characterId; //0x24
	int32_t unknown2; // 0x28 i think it's entitytype: it's used to create "guri 5 %d %d 0 %d", something_with(unknown2), 2, (byte **)ppiVar2
	char unknown3[4]; // 0x2C
	TList<void*>* unknown4; // 0x30 empty list in my case
	char unknown5[68]; //0x34
	int16_t npcTalkRange; // 0x78
	int16_t unknown6; // 0x7A
	char unknown7[45];// 0x7C
	bool isResting; //0xA9
	char pad_00AA[14]; //0xAA
};
static_assert(sizeof(TPlayerObjManager) == 0xB8, "TPlayerObjManager does not have a size of 0xB8");

#pragma pack(pop)
