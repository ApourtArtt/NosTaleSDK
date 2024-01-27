module;
#include <stdint.h>
export module TEWScrollBar;
import TEWControlWidget;


namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWScrollBar : public TEWControlWidget
	{
		struct TEWScrollBarTrack* scrollTrack;						// 0x68
		struct TEWGraphicButtonWidget* buttonScrollPreviousWidget;	// 0x6C
		struct TEWGraphicButtonWidget* buttonScrollNextWidget;		// 0x70
		int32_t unknown13;									// 0x74 if 0, the scrollbar is white, else it applies the style
		char callback[8];									// 0x78 eax is equal to parent, and ecx to index of scroll (0 top, 1 scrolled once, etc)
	};
	static_assert(sizeof(TEWScrollBar) == 0x80, "TEWScrollBar does not have a size of 0x80.");
#pragma pack(pop)
}