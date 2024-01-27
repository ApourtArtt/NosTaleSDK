module;
#include <stdint.h>
export module TEWGraphicButtonWidget;
import TEWCustomButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)

	export struct TEWGraphicButtonWidget : public TEWCustomButtonWidget
	{
		char unknown24[4];	// 0xD8
	};
	static_assert(sizeof(TEWGraphicButtonWidget) == 0xDC, "TEWGraphicButtonWidget does not have a size of 0xDC.");
#pragma pack(pop)
}