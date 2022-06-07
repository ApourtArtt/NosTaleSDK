#pragma once
#include "TEWControlWidget.h"
#include "../Properties/Graphical/GhostBorder.h"
#pragma pack(push, 1)

class TEWParentMoveWidget : public TEWControlWidget
{
public:
	TEWParentMoveWidget(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWControlWidget(VTable, EvenThing, Parent, Childs, Border)
	{

	}

protected:
	bool isBeingClickedOn;			// 0x68
	int16_t clickPositionX;			// 0x69
	int16_t clickPositionY;			// 0x6B
	bool canMove;					// 0x6D
	bool shouldStayInParentBorder;	// 0x6E
	char unknown13;					// 0x6F
	GhostBorder ghostBorder;		// 0x70
};
static_assert(sizeof(TEWParentMoveWidget) == 0x78, "TEWParentMoveWidget does not have a size of 0x78.");

#pragma pack(pop)
