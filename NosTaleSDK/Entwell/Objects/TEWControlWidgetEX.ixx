module;
#include <stdint.h>
export module TEWControlWidgetEX;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWControlWidgetEX : public TEWControlWidget
	{
	};
	static_assert(sizeof(TEWControlWidgetEX) == 0x68, "TEWControlWidgetEX does not have a size of 0x68.");
#pragma pack(pop)
}
