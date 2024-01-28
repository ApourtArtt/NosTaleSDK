module;
#include <stdint.h>
export module TNTSpecialDragonFx;
import TMapObjFxItem;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpecialDragonFx : public TMapObjFxItem
	{
		int32_t weirdCounter; // 0x0C
		char auraStyle[4]; // 0x10
		char unknown2[4]; // 0x14
	};
	static_assert(sizeof(TNTSpecialDragonFx) == 0x18, "TNTSpecialDragonFx does not have a size of 0x18.");
#pragma pack(pop)
}