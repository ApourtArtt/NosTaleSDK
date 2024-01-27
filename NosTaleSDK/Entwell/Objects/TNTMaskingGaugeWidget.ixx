module;
#include <stdint.h>
export module TNTMaskingGaugeWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTMaskingGaugeWidget : public TLBSWidget
	{
		char unknown3[36]; // 0x24
		int32_t maxValue; // 0x48
		int32_t currentValue; // 0x4C
		char unknown4[28]; // 0x50
		struct TLBSWidget* widget; // 0x5C Very often a TEWLabel, but can't be relied on. Sad.
	};
	static_assert(sizeof(TNTMaskingGaugeWidget) == 0x70, "TNTMaskingGaugeWidget does not have a size of 0x70");
#pragma pack(pop)
}