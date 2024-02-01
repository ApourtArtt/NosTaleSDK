module;
#include <stdint.h>
export module TEWScrollBarTrack;
import TEWCustomPanelWidget;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWScrollBarTrack : public TEWCustomPanelWidget
	{
		char unknown30[4];						// 0x0A4
		struct TEWScrollBarThumb* scrollThumb;	// 0x0A8
		int16_t currentIndex;					// 0x0AC
		int16_t count;							// 0x0AE
		bool isHorizontal;						// 0x0B0
		char unknown31;							// 0x0B1
		int16_t unknown32;						// 0x0B2
		int32_t unknown33;						// 0x0B4
		float scrollStep;						// 0x0B8
		char unknown34[4];						// 0x0BC
		Properties::Logical::Callback callback;	// 0x0C0
		bool isPressed;							// 0x0C8
		char unknown35;							// 0x0C9
		int16_t clickPosition;					// 0x0CA
		char unknown36[12];						// 0x0CC
	};
	static_assert(sizeof(TEWScrollBarTrack) == 0xD8, "TEWScrollBarTrack size isn't 0xD8.");
	static_assert(sizeof(TEWScrollBarTrack) <= 0xD8, "TEWScrollBarTrack size is upper than 0xD8.");
	static_assert(sizeof(TEWScrollBarTrack) >= 0xD8, "TEWScrollBarTrack size is lower than 0xD8.");
#pragma pack(pop)
}