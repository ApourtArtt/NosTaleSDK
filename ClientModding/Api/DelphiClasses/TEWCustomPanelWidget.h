#pragma once
#include "TEWMoveWidget.h"
#include "../Properties/Graphical/ImagePadding.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

/**
 * @brief Representation of the game TEWCustomPanelWidget structure.
 */
class TEWCustomPanelWidget : public TEWMoveWidget
{
public:
	TEWCustomPanelWidget(int VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWMoveWidget(VTable, EvenThing, Parent, Childs, Border)
	{

	}

	TEWCustomPanelWidget(TLBSWidget* Parent, Border Border, ImageData PanelImage, ImagePadding ImagePadding, int VTable = ClassSearcher::GetClassInfoFromName("TEWCustomPanelWidget").GetVTable())
		: TEWMoveWidget(VTable
		, 0x01, Parent, nullptr, Border)
		, imagePadding(ImagePadding)
	{
		setImageData(PanelImage);
		unknown15 = 5;
	}

	void incrementSize(int16_t incX, int16_t incY)
	{
		TLBSWidget::incrementSize(incX, incY);
		imagePadding.setWidthMiddle(imagePadding.getWidthMiddle() + incX);
		imagePadding.setPosRight(imagePadding.getPosRight() + incX);
		imagePadding.setHeightMiddle(imagePadding.getHeightMiddle() + incY);
		imagePadding.setPosBot(imagePadding.getPosBot() + incY);
	}

	void setImagePadding(ImagePadding ImagePadding) { imagePadding = ImagePadding; }
	ImagePadding getImagePadding() const { return imagePadding; }

protected:
	char unknown15;							// 0x80
	char unknown16[8];						// 0x80
	ImagePadding imagePadding;				// 0x89
	char unknown17[9];						// 0X99
	uint8_t nbUsablePictureViews;			// 0xA2 Holds how many views this object will use
	char unknown18;							// 0xA3
};
static_assert(sizeof(TEWCustomPanelWidget) == 0xA4, "TEWCustomPanelWidget does not have a size of 0xA4.");

#pragma pack(pop)