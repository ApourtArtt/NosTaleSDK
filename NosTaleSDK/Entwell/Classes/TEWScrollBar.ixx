module;
#include <stdint.h>
export module TEWScrollBar;
import TEWControlWidget;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWScrollBar : public TEWControlWidget
	{
		struct TEWScrollBarTrack* scrollTrack;								// 0x068
		struct TEWGraphicButtonWidget* buttonPrevious;						// 0x06C
		struct TEWGraphicButtonWidget* buttonNext;							// 0x070
		int32_t unknown20;													// 0x074 related to color
		struct NosTaleSDK::Entwell::Properties::Logical::Callback callback;	// 0x078
	};
	static_assert(sizeof(TEWScrollBar) == 0x80, "TEWScrollBar size isn't 0x80.");
	static_assert(sizeof(TEWScrollBar) <= 0x80, "TEWScrollBar size is upper than 0x80.");
	static_assert(sizeof(TEWScrollBar) >= 0x80, "TEWScrollBar size is lower than 0x80.");
#pragma pack(pop)
}