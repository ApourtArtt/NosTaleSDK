#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

class TEWScrollBarThumb : public TEWCustomPanelWidget
{
public:
	TEWScrollBarThumb(TLBSWidget* Parent, Border Border, ImageData PanelImage, ImagePadding ImagePadding)
		: TEWCustomPanelWidget(Parent, Border, PanelImage, ImagePadding, 
			ClassSearcher::GetClassInfoFromName("TEWScrollBarThumb").GetVTable())
	{
		unknown15 = 3;
	}

private:
	char unknown19[4];	// 0xA4 Seems unused, but weird, since it is the only add about TEWCustomPanelWidget
						// So maybe it is used only if parent has some differents values from the scrollbar.
						// Tested on (Title in P)
};
static_assert(sizeof(TEWScrollBarThumb) == 0xA8, "TEWScrollBarThumb does not have a size of 0xA8.");

#pragma pack(pop)
