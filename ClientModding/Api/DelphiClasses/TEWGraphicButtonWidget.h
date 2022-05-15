#pragma once
#include "TEWCustomButtonWidget.h"
#include "../Properties/Graphical/ImageData.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

/**
 * @brief Representation of the game TEWGraphicButtonWidget structure.
 */
class TEWGraphicButtonWidget : public TEWCustomButtonWidget
{
public:
	TEWGraphicButtonWidget(TLBSWidget* Parent, Border Border, Bgra ButtonBgra, ImageData ButtonImages, ImagePadding ImagePadding, Callback Callback, char Unknown15, int8_t NbUsablePictureViews, int VTable = ClassSearcher::GetClassInfoFromName("TEWGraphicButtonWidget").GetVTable())
		: TEWCustomButtonWidget(VTable, 0x1, Parent, nullptr, Border)
	{
		callback = Callback;
		isHandlingClick = true;
		nbUsablePictureViews = NbUsablePictureViews;
		unknown15 = Unknown15; // This value is weird. from 0 to 5 it drastically changes the button style

		setWidgetBgra(ButtonBgra);
		setImageData(ButtonImages);
		setImagePadding(ImagePadding);
	}

protected:
	char unknown24[4];	// 0xD8
};
static_assert(sizeof(TEWGraphicButtonWidget) == 0xDC, "TEWGraphicButtonWidget does not have a size of 0xDC.");

#pragma pack(pop)