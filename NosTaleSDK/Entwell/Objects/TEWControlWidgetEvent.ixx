module;
#include <stdint.h>
export module TEWControlWidgetEvent;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)

	export struct TEWControlWidgetEvent : public TEWControlWidget
	{
		char unknown13[8]; // 0x68
	};
	static_assert(sizeof(TEWControlWidgetEvent) == 0x70, "TEWControlWidgetEvent does not have a size of 0x70.");
#pragma pack(pop)
}