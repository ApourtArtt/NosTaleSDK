module;
#include <stdint.h>
export module TPlayerObjManager;
import TObject;
template<typename> struct TList;
import Position;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TPlayerObjManager : public TObject
	{
		Properties::Logical::Position position;		// 0x004
		Properties::Logical::Position destination;	// 0x008
		int32_t timestampLastAttack;				// 0x00C
		char unknown[4];							// 0x010
		int32_t currentState;						// 0x014 1=picking up, 2=attacking, 3=second weapon, 4=walking to cast skill
		struct TByteList* byteList;					// 0x018
		char unknown2[4];							// 0x01C
		struct TMapPlayerObj* mapPlayerObj;			// 0x020
		int32_t characterId;						// 0x024
		int32_t unknown3;							// 0x028 maybe entityType
		char unknown4[4];							// 0x02C
		TList<void*>* unknown5;						// 0x030
		char unknown6[58];							// 0x034
		int16_t rangeBonus;							// 0x06E
		char unknown7[8];							// 0x070
		int16_t npcTalkRange;						// 0x078
		int16_t unknown8;							// 0x07A
		char unknown9[28];							// 0x07C
		bool isMouseInvented;						// 0x098
		bool unknown10[15];							// 0x099
		bool isMovementLocked;						// 0x0A8
		bool isResting;								// 0x0A9
		char unknown11[14];							// 0x0AA
	};
	static_assert(sizeof(TPlayerObjManager) == 0xB8, "TPlayerObjManager size isn't 0xB8.");
	static_assert(sizeof(TPlayerObjManager) <= 0xB8, "TPlayerObjManager size is upper than 0xB8.");
	static_assert(sizeof(TPlayerObjManager) >= 0xB8, "TPlayerObjManager size is lower than 0xB8.");
#pragma pack(pop)
}