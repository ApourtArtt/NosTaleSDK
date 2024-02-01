module;
#include <stdint.h>
export module TEWMoveWidget;
import TEWControlWidgetEvent;
import Position;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWMoveWidget : public TEWControlWidgetEvent
	{
		bool isBeingDragged;						// 0x070
		Properties::Logical::Position currentClick;	// 0x071
		bool isMovable;								// 0x075
		bool isScreenBounded;						// 0x076
		char unknown22;								// 0x077
		int16_t lockLeftMargin;						// 0x078 Screen size offset
		int16_t lockTopMargin;						// 0x07A
		int16_t lockRightMargin;					// 0x07C
		int16_t lockBotMargin;						// 0x07E
	};
	static_assert(sizeof(TEWMoveWidget) == 0x80, "TEWMoveWidget size isn't 0x80.");
	static_assert(sizeof(TEWMoveWidget) <= 0x80, "TEWMoveWidget size is upper than 0x80.");
	static_assert(sizeof(TEWMoveWidget) >= 0x80, "TEWMoveWidget size is lower than 0x80.");
#pragma pack(pop)
}