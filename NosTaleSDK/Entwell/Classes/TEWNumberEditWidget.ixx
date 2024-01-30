module;
#include <stdint.h>
export module TEWNumberEditWidget;
import TEWEditWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWNumberEditWidget : public TEWEditWidget
	{
		char unknown32[4];	// 0x0E4
		bool isLimited;		// 0x0E8
		char unknown33[3];	// 0x0E9
		int32_t minValue;	// 0x0EC
		int32_t maxValue;	// 0x0F0
	};
	static_assert(sizeof(TEWNumberEditWidget) == 0xF4, "TEWNumberEditWidget size isn't 0xF4.");
	static_assert(sizeof(TEWNumberEditWidget) <= 0xF4, "TEWNumberEditWidget size is upper than 0xF4.");
	static_assert(sizeof(TEWNumberEditWidget) >= 0xF4, "TEWNumberEditWidget size is lower than 0xF4.");
#pragma pack(pop)
}