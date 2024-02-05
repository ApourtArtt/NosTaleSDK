module;
#include <stdint.h>
export module TMapPlayerObj;
import TMapMoveObjBase;
import DelphiString;
import WeaponGlowing;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapPlayerObj : public TMapMoveObjBase
	{
		uint16_t unknown88;									// 0x1B0
		uint16_t unknown89;									// 0x1B2
		uint8_t unknown90;									// 0x1B4
		char unknown91[3];									// 0x1B5
		uint32_t unknown92;									// 0x1B8
		uint32_t unknown93;									// 0x1BC
		char unknown94[4];									// 0x1C0
		Properties::Graphical::WeaponGlowing weaponGlowing;	// 0x1C4
		char unknown96[26];									// 0x1D6
		Properties::Logical::DelphiString* unknown97;				// 0x1F0
		Properties::Logical::DelphiString* unknown98;				// 0x1F4
		Properties::Logical::DelphiString* unknown99;				// 0x1F8
		uint32_t unknown100;								// 0x1FC
		uint32_t unknown101;								// 0x200
		uint16_t unknown102;								// 0x204
		char unknown103;									// 0x206
		uint8_t weaponRarity;								// 0x207
		uint8_t weaponUpgrade;								// 0x208
		char unknown104[7];									// 0x209
	};
	static_assert(sizeof(TMapPlayerObj) == 0x210, "TMapPlayerObj size isn't 0x210.");
	static_assert(sizeof(TMapPlayerObj) <= 0x210, "TMapPlayerObj size is upper than 0x210.");
	static_assert(sizeof(TMapPlayerObj) >= 0x210, "TMapPlayerObj size is lower than 0x210.");
#pragma pack(pop)
}