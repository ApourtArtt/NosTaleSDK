module;
#include <stdint.h>
export module TEWCaptionBar;
import TEWParentMoveWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWCaptionBar : public TEWParentMoveWidget
	{
		int16_t unknown15;					// 0x78
		bool unknown16;						// 0x7A strange behaviour on right click (seems to freeze the parent)
		bool unknown17;						// 0x7B
		char unknown18[26];					// 0x7C
		char textStyle[0xB];				// 0x96
		char unknown19[3];					// 0xA1
		char textPosition[0x10];			// 0xA4
	};
	static_assert(sizeof(TEWCaptionBar) == 0xB4, "TEWCaptionBar does not have a size of 0xB4.");
#pragma pack(pop)
}
