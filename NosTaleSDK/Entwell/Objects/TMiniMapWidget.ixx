module;
#include <stdint.h>
export module TMiniMapWidget;
import TMiniMapCore;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMiniMapWidget : public TMiniMapCore
	{
		float xIconOffset;							//0x78
		float yIconOffset;							//0x7C
		char unknown13[4];							//0x80 Change on map change A0 00 B4 00 for nosville
		int32_t mapId;								//0x84
		char unknown14[4];							//0x88 Change on map change 02 00 00 00
		float xPlayerPosition;						//0x8C
		float zPlayerPosition;						//0x90
		float yPlayerPosition;						//0x94
		char unknown15[4];							//0x98
		struct TMapPlayerObj* player;						//0x9C
		struct TMapNpcObj* npc;							//0xA0
		void* unknownList;							//0xA4
		void* unknownList2;							//0xA8
		void* unknownList3;							//0xAC
		struct TList<struct TMapNpcObj>* npcsList;				//0xB0
		void* unknownList5;							//0xB4
		struct TList<struct TMapMonsterObj*>* bossList;			//0xB8
		void* unknownList7;							//0xBC
		void* unknownList8;							//0xC0
		bool displayPlayer;							//0xC4
		bool unknown16;								//0xC5
		bool unknown17;								//0xC6
		bool unknown18;								//0xC7
		bool displayNpcs;							//0xC8
		bool unknown19;								//0xC9
		bool unknown20;								//0xCA
		bool unknown21;								//0xCB
		char unknown22[8];							//0xCC
		float xCursorPosition;						//0xD4
		float yCursorPosition;						//0xD8
		uint8_t iconTypeHovered;					//0xDC 1 for portal, 3 for npc, 255 for nothing
		char unknown23[7];							//0xDD
		void* npcHint; //TMapNpcObj					//0xE4
		char unknown24[8];							//0xE8
	};
	static_assert(sizeof(TMiniMapWidget) == 0xF0, "TNTMiniMapWidget does not have a size of 0xF0.");
#pragma pack(pop)
}