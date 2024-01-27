module;
#include <stdint.h>
export module TNaviMultiSelect;
import TLBSWidget;
import TList;
import TMapNpcObj;
import TSvrCtlObjManager;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNaviMultiSelect : public TLBSWidget
	{
		int16_t mouseXPosition;											// 0x24
		int16_t mouseYPosition;											// 0x26
		TList<TMapNpcObj*>* selectedEntities;							// 0x28 NOTE: Character is not in it even when selected
		TList<TSvrCtlObjManager*>* selectedEntitiesController;			// 0x2C NOTE: Character is not in it even when selected
		char unknown3[8];												// 0x30 From assembly code I think it is a callback that is called after selecting entities, but not tried
		bool isAlsoControllingCharacter;								// 0x38 if 0, only the selected entities move, if 1, the selected entities move but also the character (even if not selected)
		char unknown4[3];												// 0x39 probably padding
	};
	static_assert(sizeof(TNaviMultiSelect) == 0x3C, "TNaviMultiSelect does not have a size of 0x3C.");
#pragma pack(pop)
}