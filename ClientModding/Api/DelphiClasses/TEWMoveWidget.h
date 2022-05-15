#pragma once
#include "TEWControlWidgetEvent.h"
#pragma pack(push, 1)

/* TODO :
* Find those 16 unknowns bytes (0x70)
*/

/**
 * @brief Representation of the game TEWMoveWidget structure.
 */
class TEWMoveWidget : public TEWControlWidgetEvent
{
public:
	TEWMoveWidget(int VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWControlWidgetEvent(VTable, EvenThing, Parent, Childs, Border)
	{

	}

	void setMovable(bool value) { isMovable = value; }

	void setLockPositionToScreen(bool value) { lockPositionToScreen = value; }

	void setLockMargin(int16_t margin)
	{
		lockLeftMargin = margin;
		lockRightMargin = margin;
		lockTopMargin = margin;
		lockBotMargin = margin;
	}

protected:
	int8_t isBeingDragged; //0x0070
	uint16_t clickPositionX; //0x0071
	uint16_t clickPositionY; //0x0073
	bool isMovable; //0x0075
	bool lockPositionToScreen; //0x0076 holds wether the widget can get out of the screen or not
	char pad_0077[1]; //0x0077
	int16_t lockLeftMargin; //0x0078 these variables hold how many pixels the widget can go outside the screen
	int16_t lockTopMargin; //0x007A
	int16_t lockRightMargin; //0x007C
	int16_t lockBotMargin; //0x007E

	// Nonee stuff
	// 0x77 seems to be opaque or something like that, it avoid displaying on != 0 for TEWCustomPanelWidget
	// 0x7F if 1 : apply following color if 2 : add the shadow on bottom, etc
};
static_assert(sizeof(TEWMoveWidget) == 0x80, "TEWMoveWidget does not have a size of 0x80.");

#pragma pack(pop)