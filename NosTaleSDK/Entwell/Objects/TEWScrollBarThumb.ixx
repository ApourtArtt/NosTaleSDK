module;
#include <stdint.h>
export module TEWScrollBarThumb;
import TEWCustomPanelWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWScrollBarThumb : public TEWCustomPanelWidget
	{
		char unknown19[4];	// 0xA4 Seems unused, but weird, since it is the only add about TEWCustomPanelWidget
		// So maybe it is used only if parent has some differents values from the scrollbar.
		// Tested on (Title in P)
	};
	static_assert(sizeof(TEWScrollBarThumb) == 0xA8, "TEWScrollBarThumb does not have a size of 0xA8.");
#pragma pack(pop)
}