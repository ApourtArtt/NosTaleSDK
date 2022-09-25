#pragma once
#include "../TEWScrollBar.h"
#include "../TEWScrollBarThumb.h"
#include "../TEWScrollBarTrack.h"
#include "../TEWGraphicButtonWidget.h"

class ScrollBar
{
public:
	typedef int16_t IndexType;
	typedef std::function<void(IndexType)> SubCallback;

	struct Style
	{
		Border border;
		Bgra widgetBgra{ 255, 255, 255, 255 };
		ImageData imageData{ 1593835568, 512, 512, new PictureDisplayer({
			PictureView(269, 272, 9, 17),
			PictureView(278, 272, 4, 17),
			PictureView(265, 272, 4, 17),
			PictureView(287, 272, 9, 17),
			PictureView(296, 272, 4, 17),
			PictureView(283, 272, 4, 17),
			PictureView(305, 272, 9, 17),
			PictureView(314, 272, 4, 17),
			PictureView(301, 272, 4, 17)
		}) };
		ImagePadding imagePadding;
		char unknown15{ 4 };
		int8_t nbUsablePictureViews{ 3 };
	};

	[[nodiscard]] explicit ScrollBar(TLBSWidget* Parent, Border Border, SubCallback Cb, IndexType MaxSimultaneousShownItems) noexcept;
	void SetCurrentItemsNumber(IndexType Value) noexcept;

private:
	void updateScrollStep();
	void updateScrollThumbPadding();

	bool canScroll();

	TEWScrollBar* scrollBar;
	TEWScrollBarTrack* scrollTrack;
	TEWScrollBarThumb* scrollThumb;
	TEWGraphicButtonWidget* buttonNext;
	TEWGraphicButtonWidget* buttonPrevious;

	SubCallback cb, cbButton;

	IndexType currentItemsNumber{ 0 };
	IndexType maxSimultaneousShownItems{ 0 };
	IndexType lastIndex{ -1 }; // Avoid TEWScrollBarThumb to send the event when already on currentMaxIndex
};
