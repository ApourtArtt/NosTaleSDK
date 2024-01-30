module;
#include <stdint.h>
export module TMapMoveObjBase;
import TMapObjBase;
import WideString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapMoveObjBase : public TMapObjBase
	{
		uint8_t direction;														// 0xA0
		uint8_t status;															// 0xA1 0=nothing, 1=rest, 10=just fought or on locomotion, 8=run, 0x2B = dance...
		uint8_t speed;															// 0xA2
		char unknown23[2];														// 0xA3
		bool canWalkInWalls;													// 0xA5
		bool isInCombat;														// 0xA6
		char unknown24;															// 0xA7
		int32_t timestampLastStatusChange;										// 0xA8
		float timestampWalking;													// 0xAC 
		float unknown25;														// 0xB0 seems related to walk step size
		struct TByteList* bytesList;											// 0xB4
		int32_t unknown26;														// 0xB8 seems related to speed (at 0 the character walks fastly)
		struct TMapObjFxList* TMapObjFxList;									// 0xBC maybe related to fairy
		uint8_t hpPercent;														// 0xC0
		uint8_t mpPercent;														// 0xC1
		char unknown27[6];														// 0xC2
		int8_t familyLevel;														// 0xC8
		char unknown28[3];														// 0xC9
		short* unknown29;														// 0xCC
		short* unknown30;														// 0xD0
		int32_t delayBeforeNextAnimation;										// 0xD4
		int16_t hidePseudonymAndEffects;										// 0xD8 Hide pseudonym, portals, green circle, wings etc
		int16_t unknown31;														// 0xDA
		float unknown32;														// 0xDC
		uint8_t unknown33;														// 0xE0
		uint8_t unknown34;														// 0xE1
		uint8_t unknown35;														// 0xE2
		uint8_t unknown36;														// 0xE3
		uint32_t unknown37;														// 0xE4
		float unknown38;														// 0xE8
		float unknown39;														// 0xEC
		float unknown40;														// 0xF0
		uint32_t unknown41;														// 0xF4 weird timestamp when 0xFC is true
		uint32_t unknown42;														// 0xF8
		uint32_t unknown43;														// 0xFC Hide every entities
		uint8_t unknown44;														// 0x100
		uint8_t unknown45;														// 0x101
		uint8_t unknown46;														// 0x102
		char unknown47;															// 0x102
		float unknown48;														// 0x104
		float unknown49;														// 0x108
		uint32_t unknown50;														// 0x10C
		uint32_t unknown51;														// 0x110
		uint32_t unknown52;														// 0x114
		bool isBusy;															// 0x118
		char unknown53[3];														// 0x119
		uint32_t unknown54;														// 0x11C
		float unknown55;														// 0x120
		uint8_t unknown56;														// 0x124 something with character axis inverting
		uint8_t unknown57;														// 0x125 seems related to above
		char unknown58[2];														// 0x126
		uint32_t unknown59;														// 0x128 maybe a timestamp related to above
		char unknown60[4];														// 0x12C
		void* unknown61;														// 0x130
		char unknown62[20];														// 0x134
		uint8_t level;															// 0x148
		uint8_t heroLevel;														// 0x149
		uint16_t unknown63;														// 0x14A
		char unknown64[4];														// 0x14C
		uint16_t actionId;														// 0x150 if != 0 => can't cast spell
		bool showShadow;														// 0x152
		bool unknown65;															// 0x153
		bool unknown66;															// 0x154 related to TNTNaviChat bar
		bool isSelected;														// 0x155
		bool isPartner;															// 0x156
		bool unknown67;															// 0x157
		bool unknown68;															// 0x158
		char unknown69[3];														// 0x159
		uint32_t unknown70;														// 0x15C related to  TLockOnMarked
		int8_t showNPCShop;														// 0x160 -1: show "P" and the name of shop if any
		uint8_t unknown71;														// 0x161
		char unknown72[2];														// 0x162
		struct NosTaleSDK::Entwell::Properties::Logical::WideString unknown73;	// 0x164
		float effectHeightMultiplier;											// 0x168 if 1.2, then everything will be 20% above
		int32_t groupId;														// 0x16C -1 if none
		int32_t familyId;														// 0x170 -1 if none
		int32_t titleId;														// 0x174 -1 if none
		uint32_t unknown74;														// 0x178
		uint32_t unknown75;														// 0x17C
		uint32_t unknown76;														// 0x180
		uint32_t unknown77;														// 0x184 -1 on player
		uint32_t unknown78;														// 0x188 -1 on player
		uint32_t unknown79;														// 0x18C -1 on player
		bool isNotTargetable;													// 0x190
		char unknown80[3];														// 0x191
		uint32_t unknown81;														// 0x194 related to walk
		uint32_t unknown82;														// 0x198
		int32_t mapId;															// 0x19C
		uint32_t unknown83;														// 0x1A0
		uint32_t unknown84;														// 0x1A4
		char unknown85;															// 0x1A8
		uint8_t unknown86;														// 0x1A9
		int8_t displayMode;														// 0x1AA 0=effect 1=effect+hp/mp 2=nothing 3=hp/mp
		int8_t questIconOverHead;												// 0x1AB Quest icon over the head like NPC
		char unknown87[4];														// 0x1AC
	};
	static_assert(sizeof(TMapMoveObjBase) == 0x1B0, "TMapMoveObjBase size isn't 0x1B0.");
	static_assert(sizeof(TMapMoveObjBase) <= 0x1B0, "TMapMoveObjBase size is upper than 0x1B0.");
	static_assert(sizeof(TMapMoveObjBase) >= 0x1B0, "TMapMoveObjBase size is lower than 0x1B0.");
#pragma pack(pop)
}