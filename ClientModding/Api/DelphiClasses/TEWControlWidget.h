#pragma once
#include "TLBSWidget.h"
#include "../Properties/Graphical/Bgra.h"
#include "../Properties/Graphical/ImageData.h"
#pragma pack(push, 1)

class TEWControlWidget : public TLBSWidget
{
public:
	explicit TEWControlWidget() {}
	TEWControlWidget(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TLBSWidget(VTable, EvenThing, Parent, Childs, Border)
		, widgetBgra(255, 255, 255, 255)
	{}

	void setWidgetBgra(Bgra WidgetBgra) { widgetBgra = WidgetBgra; }
	void setImageData(ImageData ImageData) { imageData = ImageData; }
	[[nodiscard]] ImageData getImageData() noexcept { return imageData; }

protected:
	char unknown3[28];			// 0x0024
	// 0x38 4 bytes : address for keyboard ?
	uint8_t unknown4;			// 0x0040
	Bgra widgetBgra;			// 0x0041
	char unknown5[3];			// 0x0045
	uint16_t unknown6;			// 0x0048
	uint16_t unknown7;			// 0x004A
	bool unknown8;				// 0x004C
	int8_t currentPictureViewIndex;// 0x004D
	int8_t unknown9;			// 0x004E Strange white thing on TEWCustomPanelWidget if 0x50 is false
	ImageData imageData;		// 0x004F
	char unknown10;				// 0x005D
	int16_t unknown11;			// 0x005E
	int32_t functionArgument;	// 0x0060 Probably some callbacks. Don't touch it while we don't need it
	int32_t unknown12;			// 0x0064
};
static_assert(sizeof(TEWControlWidget) == 0x68, "TEWControlWidget does not have a size of 0x68.");

#pragma pack(pop)
