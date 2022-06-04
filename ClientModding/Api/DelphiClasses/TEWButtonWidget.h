#pragma once
#include "TEWGraphicButtonWidget.h"
#include "../Properties/Graphical/TextStyle.h"
#include "../Properties/Graphical/TextPosition.h"
#pragma pack(push, 1)

// TODO: find uknown values

class TEWButtonWidget : public TEWGraphicButtonWidget
{
public:
	TEWButtonWidget(TLBSWidget* Parent, Border Border, Bgra ButtonBgra, ImageData ButtonImages, ImagePadding ImagePadding, Callback Callback, char Unknown15, int8_t NumberOfState, TextStyle TextStyle, TextPosition TextPosition, int VTable = ClassSearcher::GetClassInfoFromName("TEWButtonWidget").GetVTable())
		: TEWGraphicButtonWidget(Parent, Border, ButtonBgra, ButtonImages, ImagePadding, Callback, Unknown15, NumberOfState, VTable)
	{
		textStyle = TextStyle;
		textPosition = TextPosition;
	}

	void setText(wchar_t* text)
	{
		textPosition.setText(text);
	}

	wchar_t* getText() const
	{
		return textPosition.getText();
	}

protected:
	char pad_00DC[8]; //0x00DC
	class TextStyle textStyle; //0x00E4
	char pad_00EF[25]; //0x00EF
	class TextPosition textPosition; //0x0108
};
static_assert(sizeof(TEWButtonWidget) == 0x118, "TEWButtonWidget does not have a size of 0x118");

#pragma pack(pop)
