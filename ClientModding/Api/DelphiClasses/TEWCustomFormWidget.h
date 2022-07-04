#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

class TEWCustomFormWidget : public TEWCustomPanelWidget
{
public:
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
		unknown15 = 0x2;
	}

protected:
	char unknown19[24];		// 0x00A4 something to do with resize 0xAD for minimap
};
static_assert(sizeof(TEWCustomFormWidget) == 0x00BC, "TEWCustomFormWidget does not have a size of 0x00BC.");

#pragma pack(pop)
