#pragma once
#include "TEWControlWidget.h"
#pragma pack(push, 1)

class TEWControlWidgetEX : public TEWControlWidget
{
public:
	TEWControlWidgetEX(int VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWControlWidget(VTable, EvenThing, Parent, Childs, Border)
	{}

	TEWControlWidgetEX(TLBSWidget* Parent, Border Border, Bgra Bgra, ImageData ImageData)
		: TEWControlWidget(ClassSearcher::GetClassInfoFromName("TEWControlWidgetEX").GetVTable(), 0x1, Parent, nullptr, Border)
	{
		setWidgetBgra(Bgra);
		setImageData(ImageData);
	}

protected:
};
static_assert(sizeof(TEWControlWidgetEX) == 0x68, "TEWControlWidgetEX does not have a size of 0x68.");

#pragma pack(pop)
