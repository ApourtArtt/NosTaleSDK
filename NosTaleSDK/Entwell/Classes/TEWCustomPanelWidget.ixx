module;
#include <stdint.h>
export module TEWCustomPanelWidget;
import TEWMoveWidget;
import ImagePadding;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWCustomPanelWidget : public TEWMoveWidget
	{
		uint8_t unknown23;									// 0x080
		uint32_t unknown24;									// 0x081
		uint32_t unknown25;									// 0x085
		Properties::Graphical::ImagePadding imagePadding;	// 0x089
		uint32_t unknown26;									// 0x099
		uint32_t unknown27;									// 0x09D
		char unknown28;										// 0x0A1
		uint8_t nbUsablePictureViews;						// 0x0A2
		char unknown29;										// 0x0A3
	};
	static_assert(sizeof(TEWCustomPanelWidget) == 0xA4, "TEWCustomPanelWidget size isn't 0xA4.");
	static_assert(sizeof(TEWCustomPanelWidget) <= 0xA4, "TEWCustomPanelWidget size is upper than 0xA4.");
	static_assert(sizeof(TEWCustomPanelWidget) >= 0xA4, "TEWCustomPanelWidget size is lower than 0xA4.");
#pragma pack(pop)
}
