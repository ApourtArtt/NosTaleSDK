module;
#include <stdint.h>
export module TEWButtonWidget;
import TEWGraphicButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWButtonWidget : public TEWGraphicButtonWidget
	{
		char pad_00DC[8]; //0x00DC
		char textStyle[0xB]; //0x00E4 //TextStyle.h
		char pad_00EF[25]; //0x00EF
		char textPosition[0x10]; //0x0108 //TextPosition.h
	};
	static_assert(sizeof(TEWButtonWidget) == 0x118, "TEWButtonWidget does not have a size of 0x118");
#pragma pack(pop)
}
