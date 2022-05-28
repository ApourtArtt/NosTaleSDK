#pragma once
#include "TEWParentMoveWidget.h"
#include "../Properties/Graphical/TextPosition.h"
#include "../Properties/Graphical/TextStyle.h"
#include "../Properties/Logical/String.h"
#pragma pack(push, 1)

/**
 * @brief Representation of the game TEWCaptionBar structure.
 */
class TEWCaptionBar : public TEWParentMoveWidget
{
public:
	TEWCaptionBar(TLBSWidget* Parent, Border Border, bgra Bgra, TextStyle TextStyle, TextPosition TextPosition, GhostBorder GhostBorder = GhostBorder())
		: TEWParentMoveWidget(ClassSearcher::GetClassInfoFromName("TEWCaptionBar").GetVTable()
		, 0x1, Parent, nullptr, Border)
		, textStyle(TextStyle)
		, textPosition(TextPosition)
	{
		unknown4 = 0x2;
		canMove = true;
		shouldStayInParentBorder = true;
		isHandlingClick = true;

		ghostBorder = GhostBorder;
	}

protected:
	int16_t unknown15;					// 0x78
	bool unknown16;						// 0x7A strange behaviour on right click (seems to freeze the parent)
	bool unknown17;						// 0x7B
	char unknown18[26];					// 0x7C
	TextStyle textStyle;				// 0x96
	char unknown19[3];					// 0xA1
	TextPosition textPosition;			// 0xA4
};
static_assert(sizeof(TEWCaptionBar) == 0xB4, "TewCaptionBar does not have a size of 0xB4.");

#pragma pack(pop)