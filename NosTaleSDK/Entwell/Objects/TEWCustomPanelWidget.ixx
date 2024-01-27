module;
#include <stdint.h>
export module TEWCustomPanelWidget;
import TEWMoveWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWCustomPanelWidget : public TEWMoveWidget
	{
		char unknown15;							// 0x80
		char unknown16[8];						// 0x80
		char imagePadding[0x10];				// 0x89
		char unknown17[9];						// 0X99
		uint8_t nbUsablePictureViews;			// 0xA2 Holds how many views this object will use
		char unknown18;							// 0xA3
	};
	static_assert(sizeof(TEWCustomPanelWidget) == 0xA4, "TEWCustomPanelWidget does not have a size of 0xA4.");
#pragma pack(pop)
}
