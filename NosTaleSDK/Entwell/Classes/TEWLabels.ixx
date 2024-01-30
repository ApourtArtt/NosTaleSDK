module;
#include <stdint.h>
export module TEWLabels;
import TEWControlWidgetEX;
import TextStyle;
import Position;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWLabels : public TEWControlWidgetEX
	{
		uint8_t unknown20;																		// 0x068
		char unknown21;																			// 0x069
		int16_t nbLines;																		// 0x06A
		bool isStyleApplied;																	// 0x06C
		struct NosTaleSDK::Entwell::Properties::Graphical::TextStyle textStyle;					// 0x06D
		struct NosTaleSDK::Entwell::Properties::Logical::Position textPadding;					// 0x078
		struct NosTaleSDK::Entwell::Properties::Logical::Position textPosition;					// 0x07C
		struct NosTaleSDK::Entwell::Properties::Graphical::TextStyle* textStylePtr;				// 0x080
		struct NosTaleSDK::Entwell::Properties::Graphical::TextStyle** textPositionArrayPtr;	// 0x084
	};
	static_assert(sizeof(TEWLabels) == 0x88, "TEWLabels size isn't 0x88.");
	static_assert(sizeof(TEWLabels) <= 0x88, "TEWLabels size is upper than 0x88.");
	static_assert(sizeof(TEWLabels) >= 0x88, "TEWLabels size is lower than 0x88.");
#pragma pack(pop)
}