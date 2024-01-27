module;
#include <stdint.h>
export module TEWParentMoveWidget;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWParentMoveWidget : public TEWControlWidget
	{
		bool isBeingClickedOn;			// 0x68
		int16_t clickPositionX;			// 0x69
		int16_t clickPositionY;			// 0x6B
		bool canMove;					// 0x6D
		bool shouldStayInParentBorder;	// 0x6E
		char unknown13;					// 0x6F
		char ghostBorder[8];		// 0x70
	};
	static_assert(sizeof(TEWParentMoveWidget) == 0x78, "TEWParentMoveWidget does not have a size of 0x78.");
#pragma pack(pop)
}
