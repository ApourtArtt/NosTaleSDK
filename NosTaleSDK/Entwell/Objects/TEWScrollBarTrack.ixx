module;
#include <stdint.h>
export module TEWScrollBarTrack;
import TEWCustomPanelWidget;
import TEWScrollBarThumb;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWScrollBarTrack : public TEWCustomPanelWidget
	{
		char unknown19[4];				// 0xA4
		TEWScrollBarThumb* scrollThumb;	// 0xA8
		int16_t currentIndex;			// 0xAC
		int16_t currentMaxIndex;		// 0xAE
		bool isWorking;					// 0xB0 If you turn this to 0 and move the bar the index will be 0 (this is normally set to 1) -- seems to be 0=vertical/1=horizontal?
		char unknown20;					// 0xB1
		int16_t unknown21;				// 0xB2 Seems unused, could not find any read/write from/to it but there's not 0 for History panel
		int32_t unknown22;				// 0xB4 Same
		float scrollStep;				// 0xB8
		int32_t unknown23;				// 0xBC Unused
		char callback[8];				// 0xC0 Move scrollThumb function callback
		bool isBeingPressed;			// 0xC8 Note : only on the scrolltrack background, not on the thumb
		char unknown24;					// 0xC9 padding byte, probably
		int16_t mousePositionPressing;	// 0xCA
		char unknown25[12];				// 0xCC
	};
	static_assert(sizeof(TEWScrollBarTrack) == 0xD8, "TEWScrollBarTrack does not have a size of 0xD8.");
#pragma pack(pop)
}