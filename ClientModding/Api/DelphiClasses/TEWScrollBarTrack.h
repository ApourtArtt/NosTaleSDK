#pragma once
#include "TEWCustomPanelWidget.h"
#include "TEWScrollBarThumb.h"
#include "../Properties/Logical/Callback.h"
#pragma pack(push, 1)

class TEWScrollBarTrack : public TEWCustomPanelWidget
{
public:
	TEWScrollBarTrack()
		: TEWCustomPanelWidget(nullptr, Border(), ImageData(), ImagePadding(), ClassSearcher::GetClassInfoFromName("TEWScrollBarTrack").GetVTable())
	{
		currentIndex = 0;
		isWorking = true;
		isHandlingClick = true;
	}

	TEWScrollBarTrack(TLBSWidget* Parent, Border Border, ImageData PanelImage, ImagePadding ImagePadding, Callback Callback, TEWScrollBarThumb* ScrollThumb)
		: TEWCustomPanelWidget(Parent, Border, PanelImage, ImagePadding, ClassSearcher::GetClassInfoFromName("TEWScrollBarTrack").GetVTable())
		, scrollThumb(ScrollThumb)
		, callback(Callback)
	{
		addWidget(ScrollThumb);
		currentIndex = 0;
		isWorking = false;
		isHandlingClick = true;
		widgetBgra = Bgra(255, 255, 255, 255);
	}

	[[nodiscard]] Callback getCallback() const { return callback; }
	void setCallback(Callback Callback) { callback = Callback; }

	void setScrollBarThumb(TEWScrollBarThumb* ScrollThumb) { scrollThumb = ScrollThumb; }

	void setCurrentMaxIndex(int16_t CurrentMaxIndex) noexcept { currentMaxIndex = CurrentMaxIndex; }
	void setCurrentIndex(int16_t CurrentIndex) noexcept { currentIndex = CurrentIndex; }
	void setScrollStep(float ScrollStep) noexcept { scrollStep = ScrollStep; }

	[[nodiscard]] int16_t getCurrentIndex() const noexcept { return currentIndex; }
	[[nodiscard]] int16_t getCurrentMaxIndex() const noexcept { return currentMaxIndex; }
	[[nodiscard]] TEWScrollBarThumb* getScrollThumb() noexcept { return scrollThumb; }

protected:
	char unknown19[4];				// 0xA4
	TEWScrollBarThumb* scrollThumb;	// 0xA8
	int16_t currentIndex;			// 0xAC
	int16_t currentMaxIndex;		// 0xAE
	bool isWorking;					// 0xB0 If you turn this to 0 and move the bar the index will be 0 (this is normally set to 1) -- seems to be 0=vertical/1=horizontal?
	char unknown20;					// 0xB1
	int16_t unknown21;				// 0xB2 Seems unused, could not find any read/write from/to it but there's not 0 for History panel
	int32_t unknown22;				// 0xB4 Same
	float scrollStep;				// 0xB8
	int32_t unknown23;				// 0xBC Unused
	Callback callback;				// 0xC0 Move scrollThumb function callback
	bool isBeingPressed;			// 0xC8 Note : only on the scrolltrack background, not on the thumb
	char unknown24;					// 0xC9 padding byte, probably
	int16_t mousePositionPressing;	// 0xCA
	char unknown25[12];				// 0xCC
};
static_assert(sizeof(TEWScrollBarTrack) == 0xD8, "TEWScrollBarTrack does not have a size of 0xD8.");

#pragma pack(pop)
