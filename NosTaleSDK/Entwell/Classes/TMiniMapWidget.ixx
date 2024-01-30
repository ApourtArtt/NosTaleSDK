module;
#include <stdint.h>
export module TMiniMapWidget;
import TMiniMapCore;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMiniMapWidget : public TMiniMapCore
	{
		float xIconOffset;								// 0x078
		float yIconOffset;								// 0x07C
		uint16_t unknown24;								// 0x080 Change on map change A0 00 for nosville
		uint16_t unknown25;								// 0x082 Change on map change B4 00 for nosville
		int32_t mapId;									// 0x084
		uint8_t unknown26;								// 0x088
		char unknown27;									// 0x089
		uint16_t unknown28;								// 0x08A
		float xPlayerPosition;							// 0x08C
		uint32_t zPlayerPosition;						// 0x090
		float yPlayerPosition;							// 0x094
		uint16_t unknown29;								// 0x098
		char unknown30[2];								// 0x09A
		struct TMapPlayerObj* player;					// 0x09C
		struct TMapNpcObj* npc;							// 0x0A0
		struct TList<void*>* unknown31;					// 0x0A4
		struct TList<void*>* unknown32;					// 0x0A8
		struct TList<void*>* unknown33;					// 0x0AC
		struct TList<struct TMapNpcObj>* npcsList;		// 0x0B0
		struct TList<void*>* unknown34;					// 0x0B4
		struct TList<struct TMapMonsterObj*>* bossList;	// 0x0B8
		struct TList<void*>* unknown35;					// 0x0BC
		struct TList<void*>* unknown36;					// 0x0C0
		bool displayPlayer;								// 0x0C4
		bool unknown37;									// 0x0C5
		bool unknown38;									// 0x0C6
		bool unknown39;									// 0x0C7
		bool displayNpcs;								// 0x0C8
		bool unknown40;									// 0x0C9
		bool unknown41;									// 0x0CA
		bool unknown42;									// 0x0CB
		bool unknown43;									// 0x0CC
		bool unknown44;									// 0x0CD
		bool unknown45;									// 0x0CE
		bool unknown46;									// 0x0CF
		bool unknown47;									// 0x0D0
		bool unknown48;									// 0x0D1
		char unknown49[2];								// 0x0D2
		float xCursorPosition;							// 0x0D4
		float yCursorPosition;							// 0x0D8
		uint8_t iconTypeHovered;						// 0x0DC 1 for portal, 3 for npc, 255 for nothing
		char unknown50[3];								// 0x0DD
		uint32_t unknown51;								// 0x0E0
		struct TMapNpcObj* npcHint;						// 0x0E4
		bool unknown52;									// 0x0E8
		bool unknown53;									// 0x0E9
		char unknown54;									// 0x0EA
		bool unknown55;									// 0x0EB
		bool unknown56;									// 0x0EC
		bool unknown57;									// 0x0ED
		char unknown58[2];								// 0x0EE
	};
	static_assert(sizeof(TMiniMapWidget) == 0xF0, "TMiniMapWidget size isn't 0xF0.");
	static_assert(sizeof(TMiniMapWidget) <= 0xF0, "TMiniMapWidget size is upper than 0xF0.");
	static_assert(sizeof(TMiniMapWidget) >= 0xF0, "TMiniMapWidget size is lower than 0xF0.");
#pragma pack(pop)
}