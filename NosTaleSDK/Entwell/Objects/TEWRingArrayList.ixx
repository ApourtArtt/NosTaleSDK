module;
#include <stdint.h>
export module TEWRingArrayList;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWRingArrayList : public TObject
	{
		void* TNTMessageBoxWidgetVTable;		// 0x04
		struct TGameRootWidget* gameRootWidget;	// 0x08 TGameRootWidget in my case
		struct TNTMessageBoxWidget** messageBoxes;		// 0x0C 5 max I think
		int16_t lastUsedIndex;					// 0x10 messageBoxes[lastUsedIndex] is the last displayed
		int8_t unknown2;						// 0x12
		int8_t unknown3;						// 0x13
	};
	static_assert(sizeof(TEWRingArrayList) == 0x14, "TEWRingArrayList does not have a size of 0x14.");
#pragma pack(pop)
}