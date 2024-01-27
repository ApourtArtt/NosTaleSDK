module;
#include <stdint.h>
export module TSceneManager;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TSceneManager : public TObject
	{
		uint32_t playerListPtr; //0x0004
		uint32_t monsterListPtr; //0x0008
		uint32_t npcListPtr; //0x000C
		uint32_t itemListPtr; //0x0010
		uint32_t unknownPtr1; // 0x0014
		uint32_t unknownPtr2; // 0x0018
		uint32_t unknownPtr3; // 0x001C
		void* mapGrid; // 0x0020
		char pad_0014[8]; //0x0024
		int32_t playerID; //0x002C
		uint32_t mapPlayerObjPtr; //0x0030
		char pad_0034[32]; //0x0034
		int16_t targetSkillX; //0x0054
		int16_t targetSkillY; //0x0056
		char pad_0058[20]; //0x0058
		struct TLBSCamera* camera; //0x006C
		char pad_0070[48]; //0x0070
	};
	static_assert(sizeof(TSceneManager) == 0xA0, "TSceneManager does not have a size of 0xA0");
#pragma pack(pop)
}