module;
#include <stdint.h>
export module TMapMoveObjBase;
import TMapObjBase;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapMoveObjBase : public TMapObjBase
	{
		uint8_t direction;					// 0xA0
		uint8_t status;						// 0xA1 0=nothing, 1=rest, 10=just fought or on locomotion, 8=run, 0x2B = dance...
		uint8_t speed;						// 0xA2
		char unknown21[2];					// 0xA3
		bool checkBlockedCells;				// 0xA5
		bool isInCombat;					// 0xA6
		char unknown22;						// 0xA7
		int32_t lastStatusChangeTimestamp;	// 0xA8
		float walkingTimestamp;				// 0xAC related to above value
		float unknown23;					// 0xB0 seems related to walk step size
		void* TByteList;					// 0xB4 TODO: create struct seems related to status - not digged enough
		int32_t unknown24;					// 0xB8 seems related to speed (at 0 the character walks fastly)
		void* TMapObjFxList;				// 0xBC TODO: create struct - stores info like fairy fx etc
		uint8_t hpPercent;					// 0xC0
		uint8_t mpPercent;					// 0xC1
		char unknown25[2];					// 0xC2 probably padding
		char unknown26[4];					// 0xC4
		int8_t lvlFamily;					// 0xC8
		char unknown83[3];					// 0xC9
		void* tsmallint;					// 0xCC
		void* tsmallint2;					// 0xD0
		int32_t delayBeforeNextAnimation;	// 0xD4
		int16_t hidePseudonymAndEffects;	// 0xD8 Hide pseudonym, portals, green circle, wings etc
		char unknown27[2];					// 0xDA I don't think it's padding but could not find any write/read
		char unknown28[4];					// 0xDC
		char unknown29[4];					// 0xE0
		char unknown30[4];					// 0xE4
		char unknown31[4];					// 0xE8
		char unknown32[4];					// 0xEC
		char unknown33[4];					// 0xF0
		char unknown34[4];					// 0xF4 weird timestamp when 0xFC is true
		char unknown35[4];					// 0xF8
		char unknown36[4];					// 0xFC Hide every entities
		char unknown37[4];					// 0x100
		char unknown38[4];					// 0x104
		char unknown39[4];					// 0x108
		char unknown40[4];					// 0x10C
		char unknown41[4];					// 0x110
		char unknown42[4];					// 0x114
		char unknown43;						// 0x118 set to 1 when trying to make an action, set to 0 at the end of the action
		char unknown44[3];					// 0x119 probably padding
		char unknown45[4];					// 0x11C
		float unknown46;					// 0x120
		int8_t unknown47;					// 0x124 something with character axis inverting
		int8_t unknown48;					// 0x125 seems related to above
		char unknown49[2];					// 0x126 probably padding
		char unknown50[4];					// 0x128 maybe a timestamp related to above
		char unknown51[4];					// 0x12C W
		void* unknown52;					// 0x130 probably a pointer
		void* unknown53;					// 0x134 maybe a pointer
		void* unknown54;					// 0x138 maybe a pointer
		void* unknown55;					// 0x13C maybe a pointer
		void* unknown56;					// 0x140 maybe a pointer
		void* unknown57;					// 0x144 maybe a pointer
		uint8_t level;						// 0x148
		uint8_t levelH;						// 0x149
		bool unknown58;						// 0x14A enters a condition
		char unknown59;						// 0x14B probably padding
		int16_t unknown60;					// 0x14C
		int16_t unknown61;					// 0x14E
		int16_t cannotCastAttack;			// 0x150 If == 0, can cast skill else no (Hatz said: "isTalkable")
		bool showShadow;					// 0x152 if -1, hide shadow under entity
		int8_t unknown62;					// 0x153
		bool unknown63;						// 0x154 used in an if - is being checked to true if entitytype is 3 when tntnavichat bar is displayed...
		bool isSelected;					// 0x155 0 = orange circle, 1 = green circle
		uint16_t unknown64;					// 0x156
		char unknown65[4];					// 0x158 0x156 Hatz said "isPartner"
		char unknown66[4];					// 0x15C Seems related to 0x151 and with TLockOnTargetMark or with NPC show name, something like that also to 0x152 and tntnavichatviewer
		int8_t showNPCShop;					// 0x160 -1: show "P" and the name of shop if any
		char unknown67[3];					// 0x161 maybe padding
		char unknown68[4];					// 0x164
		float effectHeightMultiplier;		// 0x168 if 1.2, then everything will be 20% above
		int32_t groupId;					// 0x16C -1 if none
		int32_t familyId;					// 0x170 -1 if none
		int32_t titleId;					// 0x174 -1 if none
		char unknown69[4];					// 0x178
		char unknown70[4];					// 0x17C
		char unknown71[4];					// 0x180
		char unknown72[4];					// 0x184 -1 on player
		char unknown73[4];					// 0x188 -1 on player
		char unknown74[4];					// 0x18C -1 on player
		char unknown75[4];					// 0x190 Hatz said "notTargetable" as byte and 3 padding
		int32_t unknown76;					// 0x194 used when walking
		char unknown77[4];					// 0x198
		int32_t mapId;						// 0x19C
		char unknown78[4];					// 0x1A0
		char unknown79[4];					// 0x1A4
		int8_t unknown80;					// 0x1A8
		int8_t unknown81;					// 0x1A9
		int8_t displayMode;					// 0x1AA 0=effect 1=effect+hp/mp 2=nothing 3=hp/mp
		int8_t questIconOverHead;			// 0x1AB Quest icon over the head like NPC
		char unknown82[4];					// 0x1AC
	};
	static_assert(sizeof(TMapMoveObjBase) == 0x1B0, "TMapMoveObjBase does not have a size of 0x1B0.");
#pragma pack(pop)
}