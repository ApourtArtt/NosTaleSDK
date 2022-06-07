#pragma once
#include "TEWControlWidgetEX.h"
#include "../Properties/Graphical/TextStyle.h"
#include "../Properties/Graphical/TextPosition.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
* Make it possible to configure pxBeforeTextX/Y, x/y
*/

class TEWLabel : public TEWControlWidgetEX
{
public:
	static constexpr std::string_view NAME = "TEWLabel";
	explicit TEWLabel() {}
	TEWLabel(TLBSWidget* Parent, Border Border, TextStyle TextStyle, TextPosition TextPosition)
		: TEWControlWidgetEX(ClassSearcher::GetClassInfoFromName("TEWLabel").GetVTable()
		, 0x21, Parent, nullptr, Border)
		, unknown14(1)
		, textStyle(TextStyle)
		, textPosition(TextPosition)
	{

	}

	void setText(wchar_t* text)
	{
		textPosition.setText(text);
	}

	wchar_t* getText() const { return textPosition.getText(); }

	TextPosition& getTextPosition() { return textPosition; }

	void setPxPerLine(int16_t px) { textPosition.setPxPerLine(px); }

protected:
	char unknown14;				// 0x68 avoid parent from displaying on 0
	char unknown15;				// 0x69 avoid TEWLabel from displaying itself on != 0
	TextStyle textStyle;		// 0x6A
	char unknown16[3];			// 0x75
	TextPosition textPosition;	// 0x78
	char unknown17[8];			// 0x88
};
static_assert(sizeof(TEWLabel) == 0x90, "TEWLabel does not have a size of 0x90.");

#pragma pack(pop)
