module;
#include <stdint.h>
export module TEWControlWidgetMouseEvent;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWControlWidgetMouseEvent : public TEWControlWidget
	{
		char unknown13[0x40]; // 0x68
	};
	static_assert(sizeof(TEWControlWidgetMouseEvent) == 0xA8, "TEWControlWidgetMouseEvent does not have a size of 0xA8.");
#pragma pack(pop)
}
