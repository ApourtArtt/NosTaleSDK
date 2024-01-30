module;
#include <stdint.h>
export module TNTSpecialDragonFx;
import TMapObjFxItem;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpecialDragonFx : public TMapObjFxItem
	{
		int32_t counter;	// 0x00C
		uint32_t auraStyle;	// 0x010
		uint8_t unknown3;	// 0x014
		char unknown4[3];	// 0x015
	};
	static_assert(sizeof(TNTSpecialDragonFx) == 0x18, "TNTSpecialDragonFx size isn't 0x18.");
	static_assert(sizeof(TNTSpecialDragonFx) <= 0x18, "TNTSpecialDragonFx size is upper than 0x18.");
	static_assert(sizeof(TNTSpecialDragonFx) >= 0x18, "TNTSpecialDragonFx size is lower than 0x18.");
#pragma pack(pop)
}