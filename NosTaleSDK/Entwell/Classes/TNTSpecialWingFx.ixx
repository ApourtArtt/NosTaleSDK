module;
#include <stdint.h>
export module TEWButtonWidget;
import TMapObjFxItem;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTSpecialWingFx : public TMapObjFxItem
	{
		int32_t count;			// 0x00C
		uint32_t wingStyle;		// 0x010
		uint8_t unknown3;		// 0x014
		char unknown4[3];		// 0x015
	};
	static_assert(sizeof(TNTSpecialWingFx) == 0x18, "TNTSpecialWingFx size isn't 0x18.");
	static_assert(sizeof(TNTSpecialWingFx) <= 0x18, "TNTSpecialWingFx size is upper than 0x18.");
	static_assert(sizeof(TNTSpecialWingFx) >= 0x18, "TNTSpecialWingFx size is lower than 0x18.");
#pragma pack(pop)
}