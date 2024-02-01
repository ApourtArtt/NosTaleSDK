module;
#include <stdint.h>
export module TEWParentMoveWidget;
import TEWControlWidget;
import Position;
import Border;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWParentMoveWidget : public TEWControlWidget
	{
		bool isClicked;								// 0x068
		Properties::Logical::Position currentClick;	// 0x069
		bool isMovable;								// 0x06D
		bool isBoundedByParent;						// 0x06E
		uint8_t unknown20;							// 0x06F
		Properties::Graphical::Border ghostBorder;	// 0x070
	};
	static_assert(sizeof(TEWParentMoveWidget) == 0x78, "TEWParentMoveWidget size isn't 0x78.");
	static_assert(sizeof(TEWParentMoveWidget) <= 0x78, "TEWParentMoveWidget size is upper than 0x78.");
	static_assert(sizeof(TEWParentMoveWidget) >= 0x78, "TEWParentMoveWidget size is lower than 0x78.");
#pragma pack(pop)
}
