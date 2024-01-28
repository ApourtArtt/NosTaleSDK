module;
#include <stdint.h>
export module TEWButtonWidget;
import TMapObjFxItem;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpecialWingFx : public TMapObjFxItem
	{
		int32_t weirdCounter; // 0x0C
		char wingStyle[4]; // 0x10
		char unknown2[4]; // 0x14
	};
	static_assert(sizeof(TNTSpecialWingFx) == 0x18, "TNTSpecialWingFx does not have a size of 0x18.");
#pragma pack(pop)
}