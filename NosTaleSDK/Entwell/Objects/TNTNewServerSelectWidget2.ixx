module;
#include <stdint.h>
export module TNTNewServerSelectWidget2;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewServerSelectWidget2 : public TEWControlWidgetEX
	{
		char unknown13[0x18];
		TEWControlWidgetEX* serverTrackerWidget;
		char unknown14[0x1E0];
	};
	static_assert(sizeof(TNTNewServerSelectWidget2) == 0x264, "TNTNewServerSelectWidget2 does not have a size of 0x264.");
#pragma pack(pop)
}