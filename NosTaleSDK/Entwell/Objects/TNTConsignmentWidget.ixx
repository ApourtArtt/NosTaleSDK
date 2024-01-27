module;
#include <stdint.h>
export module TNTConsignmentWidget;
import TEWCustomFormWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTConsignmentWidget : public TEWCustomFormWidget
	{
		char unknown20[4]; // 0x00BC
		struct TEWControlWidgetMouseEvent* content; // 0x00C0
		char unknown21[0x6B8]; // 0x00C4
	};
	static_assert(sizeof(TNTConsignmentWidget) == 0x077C, "TNTConsignmentWidget does not have a size of 0x077C.");
#pragma pack(pop)
}