module;
#include <stdint.h>
export module TSceneManager;
import TObject;
import Position;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TSceneManager : public TObject
	{
		void* playerListPtr;														// 0x004
		void* monsterListPtr;														// 0x008
		void* npcListPtr;															// 0x00C
		void* itemListPtr;															// 0x010
		void* unknown;																// 0x014
		void* unknown2;																// 0x018
		struct LBSBkFxList* unknown3;												// 0x01C
		struct MapGrid* mapGrid;													// 0x020
		int32_t timestamp;															// 0x024
		char unknown4[4];															// 0x028
		int32_t playerId;															// 0x02C
		struct TMapPlayerObj* mapPlayerObjPtr;										// 0x030
		char unknown5[8];															// 0x034
		struct TSvrCtlObjManager* objManager;										// 0x03C
		char unknown6[8];															// 0x040 Camera related change when move with right click
		char unknown7[4];															// 0x048
		struct NosTaleSDK::Entwell::Properties::Logical::Position cursorPosition;	// 0x04C
		int16_t windowWidth;														// 0x050
		int16_t windowHeight;														// 0x052
		struct NosTaleSDK::Entwell::Properties::Logical::Position targetSkillPos;	// 0x054
		bool isCursorOnWindow;														// 0x058
		char unknown8[3];															// 0x059
		char unknown9[12];															// 0x05C related to cursor deplacement
		char unknown10[4];															// 0x068 related to cursor deplacement
		struct TLBSCamera* camera;													// 0x06C
		struct TList<void*>* unknown11;												// 0x070
		struct TList<void*>* unknown12;												// 0x074
		struct TList<void*>* unknown13;												// 0x078
		struct TList<void*>* unknown14;												// 0x07C
		struct TList<void*>* unknown15;												// 0x080
		struct TList<struct TLBSBkFxItem*>* fxList;									// 0x084
		char unknown16[12];															// 0x088
		void* unknown17;															// 0x094
		int16_t unknown18;															// 0x098
		char unknown19[6];															// 0x09A
	};
	static_assert(sizeof(TSceneManager) == 0xA0, "TSceneManager size isn't 0xA0.");
	static_assert(sizeof(TSceneManager) <= 0xA0, "TSceneManager size is upper than 0xA0.");
	static_assert(sizeof(TSceneManager) >= 0xA0, "TSceneManager size is lower than 0xA0.");
#pragma pack(pop)
}