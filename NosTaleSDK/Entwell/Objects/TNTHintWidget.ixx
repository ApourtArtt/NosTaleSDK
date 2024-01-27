module;
#include <stdint.h>
export module TNTHintWidget;
import TEWLabels;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTHintWidget : public TEWLabels
	{
		char unknown15[24];
	};
	static_assert(sizeof(TNTHintWidget) == 0xA0, "TNTHintWidget does not have a size of 0xA0.");
#pragma pack(pop)
}