module;
#include <stdint.h>
export module TEWRingArrayList;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWRingArrayList : public TObject
	{
		void* TNTMessageBoxWidgetVTable;			// 0x004
		struct TGameRootWidget* gameRootWidget;		// 0x008 TGameRootWidget in my case
		struct TNTMessageBoxWidget** messageBoxes;	// 0x00C 5 max I think
		int16_t lastUsedIndex;						// 0x010
		int8_t unknown2;							// 0x012
		int8_t unknown3;							// 0x013
	};
	static_assert(sizeof(TEWRingArrayList) == 0x14, "TEWRingArrayList size isn't 0x14.");
	static_assert(sizeof(TEWRingArrayList) <= 0x14, "TEWRingArrayList size is upper than 0x14.");
	static_assert(sizeof(TEWRingArrayList) >= 0x14, "TEWRingArrayList size is lower than 0x14.");
#pragma pack(pop)
}