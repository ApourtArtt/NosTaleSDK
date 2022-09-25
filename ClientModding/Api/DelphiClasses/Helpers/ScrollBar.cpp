#include "ScrollBar.h"
#include "../../../MemoryHelper/PatternScan.h"

namespace
{
	void __fastcall onScroll(ScrollBar::IndexType index, TEWScrollBarTrack* scrollTrack)
	{
		ScrollBar::SubCallback cb = *reinterpret_cast<ScrollBar::SubCallback*>(scrollTrack->getCallback().getArg());
		cb(index);
	}

	uintptr_t getNextButtonFunc()
	{
		uintptr_t* patternAddr = (uintptr_t*)PatternScan("\x89\x46\x41\x8b\x43\x68\x89\x86\xb4\x00\x00\x00\xc7\x86\xb0\x00\x00\x00\x00\x00\x00\x00\x8b\xcb\xb2\x01",
			"xxxxxxxxxxxxxxxxxx????xxxx",
			18
		);
		if (patternAddr == nullptr || *(uintptr_t*)patternAddr == NULL)
		{
			Logger::Error("ScrollBar::getNextButtonFunc() pattern is not valid");
			return NULL;
		}
		Logger::Log("ScrollBar::getNextButtonFunc() %x", *(uintptr_t*)patternAddr);
		return *(uintptr_t*)patternAddr;
	}

	uintptr_t getPreviousButtonFunc()
	{
		uintptr_t* patternAddr = (uintptr_t*)PatternScan("\x89\x46\x41\x8b\x43\x68\x89\x86\xb4\x00\x00\x00\xc7\x86\xb0\x00\x00\x00\x00\x00\x00\x00\xc6\x43\x74\x01\x8b\xc3",
			"xxxxxxxxxxxxxxxxxx????xxxxxx",
			18
		);
		if (patternAddr == nullptr || *(uintptr_t*)patternAddr == NULL)
		{
			Logger::Error("ScrollBar::getPreviousButtonFunc() pattern is not valid");
			return NULL;
		}
		Logger::Log("ScrollBar::getPreviousButtonFunc() %x", *(uintptr_t*)patternAddr);
		return *(uintptr_t*)patternAddr;
	}
}

ScrollBar::ScrollBar(TLBSWidget* Parent, Border BorderWidget, SubCallback Cb, IndexType MaxSimultaneousShownItems) noexcept
	: maxSimultaneousShownItems(MaxSimultaneousShownItems)
{
	cb = SubCallback([this, Cb](IndexType index)
	{
		if (index < 0 || index == lastIndex || !canScroll())
			return;
		lastIndex = index;
		Cb(index);
	});

	scrollBar = new TEWScrollBar(Parent, BorderWidget, Callback(onScroll, &cb));

	scrollThumb = new TEWScrollBarThumb();
	scrollThumb->setWidgetBorder(Border(0, 0, 17, 37));
	scrollThumb->setWidgetBgra(Bgra(255, 255, 255, 255));
	scrollThumb->setImageData(ImageData(1593835568, 512, 512, new PictureDisplayer(
	{
		PictureView(476, 361, 17, 7),
		PictureView(476, 356, 17, 5),
		PictureView(476, 368, 17, 6),
	})));
	scrollThumb->setImagePadding(ImagePadding(17, 26, 17, 31, 0, 5, 0, 6));

	scrollTrack = new TEWScrollBarTrack(
		scrollBar,
		Border(0, 18, 17, scrollBar->getBorder().getHeight() - 34),
		ImageData(1593835568, 512, 512, new PictureDisplayer(
		{
			PictureView(507, 401, 3, 1),
			PictureView(506, 400, 1, 1),
			PictureView(507, 400, 3, 1),
			PictureView(510, 400, 1, 1),
			PictureView(510, 401, 1, 1),
			PictureView(510, 402, 1, 1),
			PictureView(507, 402, 3, 1),
			PictureView(506, 402, 1, 1),
			PictureView(506, 401, 1, 1),
		})),
		ImagePadding(15, scrollBar->getBorder().getHeight() - 18 - 2, 16, scrollBar->getBorder().getHeight() - 18 - 1, 1, 1, 1, 1),
		Callback(onScroll, &cb),
		scrollThumb
	);
	scrollTrack->setUnknown15(4);
	scrollThumb->setWidgetParent(scrollTrack);

	buttonNext = new TEWGraphicButtonWidget(
		scrollBar,
		Border(0, 0, 17, 18),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer(
		{
			PictureView(476, 332, 17, 18),
		})),
		ImagePadding(),
		Callback(getNextButtonFunc(), scrollTrack),
		0, 1
	);

	buttonPrevious = new TEWGraphicButtonWidget(
		scrollBar,
		Border(0, scrollBar->getBorder().getHeight() - 17, 17, 18),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer(
		{
			PictureView(476, 381, 17, 18),
		})),
		ImagePadding(),
		Callback(getPreviousButtonFunc(), scrollTrack),
		0, 1
	);

	scrollBar->addWidget(scrollTrack);
	scrollBar->addWidget(buttonNext);
	scrollBar->addWidget(buttonPrevious);

	scrollBar->setScrollTrack(scrollTrack);
	scrollBar->setNextButton(buttonNext);
	scrollBar->setPreviousButton(buttonPrevious);

	Parent->addWidget(scrollBar);

	scrollThumb->setVisible(false);
	scrollTrack->setVisible(true);
	buttonNext->setVisible(true);
	buttonPrevious->setVisible(true);
	scrollBar->setVisible(true);

	Logger::Log("ScrollBar: %x, ScrollTrack: %x, ScrollThumb: %x", scrollBar, scrollTrack, scrollThumb);
}

void ScrollBar::SetCurrentItemsNumber(IndexType Value) noexcept
{
	currentItemsNumber = Value;
	auto actualIndex = currentItemsNumber - maxSimultaneousShownItems;
	if (actualIndex < 0) actualIndex = 0;
	scrollTrack->setCurrentMaxIndex(actualIndex);
	updateScrollStep();
	updateScrollThumbPadding();
}

void ScrollBar::updateScrollStep()
{
	if (!canScroll())
	{
		scrollThumb->setVisible(false);
		scrollTrack->setScrollStep(0.f);
		return;
	}

	/*
		*(float *)(param_1 + 0xb8) = (float)((int)(short)uVar2 - (int)(short)uVar3) / (float)*(short *)(param_1 + 0xae);

		param_1 = scrollTrack
		uVar2 = trackSize
		uVar3 = thumbSize
		param_1 + 0xae = nbMaxItem

		Pattern (2nd found):
		df 86 ae 00 00 00 de f9 d9 9e b8 00 00 00 9b df 86 ac 00 00 00 d8 8e b8 00 00 00
	*/
	float trackSize = static_cast<float>(scrollTrack->getBorder().getHeight());
	float thumbSize = static_cast<float>(scrollThumb->getBorder().getHeight());
	int16_t nbMaxItem = scrollTrack->getCurrentMaxIndex();
	float scrollStep = (trackSize - thumbSize) / static_cast<float>(nbMaxItem);
	scrollTrack->setScrollStep(scrollStep);

	scrollThumb->setVisible(true);
}

void ScrollBar::updateScrollThumbPadding()
{
	// TODO
	// 4a4298
}

bool ScrollBar::canScroll()
{
	return currentItemsNumber > maxSimultaneousShownItems;
}
