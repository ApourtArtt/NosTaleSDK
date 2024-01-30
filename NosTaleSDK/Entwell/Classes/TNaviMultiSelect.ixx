module;
#include <stdint.h>
export module TNaviMultiSelect;
import TLBSWidget;
import Position;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNaviMultiSelect : public TLBSWidget
	{
		struct NosTaleSDK::Entwell::Properties::Logical::Position mousePosition;	// 0x024
		struct TList<struct TMapNpcObj*>* selectedEntities;							// 0x028 except controlled entity
		struct TList<struct TSvrCtlObjManager*>* selectedEntitiesController;		// 0x02C except controlled entity
		uint32_t unknown5;															// 0x030 maybe callback
		uint32_t unknown6;															// 0x034 maybe callback
		bool isAlsoControllingCharacter;											// 0x038 if 0, only the selected entities move, if 1, the selected entities move but also the character (even if not selected)
		uint8_t unknown7;															// 0x039
		char unknown8[2];															// 0x03A
	};
	static_assert(sizeof(TNaviMultiSelect) == 0x3C, "TNaviMultiSelect size isn't 0x3C.");
	static_assert(sizeof(TNaviMultiSelect) <= 0x3C, "TNaviMultiSelect size is upper than 0x3C.");
	static_assert(sizeof(TNaviMultiSelect) >= 0x3C, "TNaviMultiSelect size is lower than 0x3C.");
#pragma pack(pop)
}