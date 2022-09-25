#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

class TEWCustomFormWidget : public TEWCustomPanelWidget
{
public:
	enum ResizeFlag { All = -1, NONE = 0, Top = 1, Bot = 2, TopBot = 3, Left = 4 };
	TEWCustomFormWidget(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWCustomPanelWidget(VTable, EvenThing, Parent, Childs, Border)
	{}

	TEWCustomFormWidget(TLBSWidget* Parent, Border Border, ImageData ImageData, ImagePadding ImagePadding)
		: TEWCustomPanelWidget(ClassSearcher::GetClassInfoFromName("TEWCustomFormWidget").GetVTable()
			, 0xB, Parent, nullptr, Border)
	{
		imageData = ImageData;
		unknown4 = 0x3;
		isHandlingClick = true;
		imagePadding = ImagePadding;
		if (imageData.getNbPictureViews() == 9)
			unknown15 = 0x5;
		else
			unknown15 = 0x2;
	}

	void SetResize(ResizeFlag value) {
		_resize = value;
	}

protected:
	uint32_t unknown_a; // 0x00A4
	uint32_t _caption_bar; // 0x00A8
	uint8_t unknown_b; // 0x00AC
	ResizeFlag _resize; // 0x00AD
	uint8_t unkown_c[0x7];
};
static_assert(sizeof(TEWCustomFormWidget) == 0x00BC, "TEWCustomFormWidget does not have a size of 0x00BC.");

#pragma pack(pop)
