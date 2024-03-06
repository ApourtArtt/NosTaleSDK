module;
#include <stdint.h>
export module TMapMonsterObj;
import TMapMoveObjBase;
import DelphiArray;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapMonsterObj : public TMapMoveObjBase
	{
		uint8_t unknown88;							// 0x1B0 Something related glow (1=small glow 2=huge glow like shadow monsters in Act 5.2 3+=nothing)
		char unknown89[3];							// 0x1B1
		int16_t morphVnum;							// 0x1B4
		int16_t shadowType;							// 0x1B6 if value is 2034 or 2049 the shadow is above the entity, if the value is 2371, the display removes every pseudonyms and life/mana bars - seems to have some logic with a list
		void* unknown90;							// 0x1B8 pointer to a struct storing monster info
		char unknown91;								// 0x1BC something if & 0x7F
		char unknown92[3];							// 0x1BD probably padding
		uint8_t unknown93;							// 0x1C0
		char unknown94[3];							// 0x1C1
		float unknown95;							// 0x1C4
		uint8_t unknown96;							// 0x1C8
		uint8_t unknown97;							// 0x1C9
		uint8_t unknown98;							// 0x1CA
		char unknown99;								// 0x1CB
		uint8_t unknown100;							// 0x1CC
		char unknown101[3];							// 0x1CD
		Properties::Logical::DelphiArray<char>* unknown102;	// 0x1D0
	};
	static_assert(sizeof(TMapMonsterObj) == 0x1D4, "TMapMonsterObj size isn't 0x1D4.");
	static_assert(sizeof(TMapMonsterObj) <= 0x1D4, "TMapMonsterObj size is upper than 0x1D4.");
	static_assert(sizeof(TMapMonsterObj) >= 0x1D4, "TMapMonsterObj size is lower than 0x1D4.");
#pragma pack(pop)
}