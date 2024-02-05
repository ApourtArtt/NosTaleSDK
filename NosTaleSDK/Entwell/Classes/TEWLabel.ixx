module;
#include <stdint.h>
export module TEWLabel;
import TEWControlWidgetEX;
import TextStyle;
import TextPosition;
import DelphiString;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWLabel : public TEWControlWidgetEX
	{
		bool isBackgroundTransparent;															// 0x068
		uint8_t unknown21;																		// 0x069
		Properties::Graphical::TextStyle textStyle;												// 0x06A
		char unknown22[3];																		// 0x075
		Properties::Graphical::TextPosition<Properties::Logical::DelphiWString> textPosition;	// 0x078
		uint32_t unknown23;																		// 0x088
		uint32_t unknown24;																		// 0x08C
	};
	static_assert(sizeof(TEWLabel) == 0x90, "TEWLabel size isn't 0x90.");
	static_assert(sizeof(TEWLabel) <= 0x90, "TEWLabel size is upper than 0x90.");
	static_assert(sizeof(TEWLabel) >= 0x90, "TEWLabel size is lower than 0x90.");
#pragma pack(pop)
}
