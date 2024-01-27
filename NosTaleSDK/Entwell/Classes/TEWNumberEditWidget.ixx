module;
#include <stdint.h>
export module TEWNumberEditWidget;
import TEWEditWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWNumberEditWidget : public TEWEditWidget
	{
		char unknown20[4];			// 0xE4
		bool isLimited;				// 0xE8
		char unknown21[3];			// 0xE9
		int32_t minValue;			// 0xEC
		int32_t maxValue;			// 0xF0
	};
	static_assert(sizeof(TEWNumberEditWidget) == 0xF4, "TEWNumberEditWidget does not have a size of 0xF4.");
#pragma pack(pop)
}