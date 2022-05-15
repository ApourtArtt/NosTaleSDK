#pragma once
#include "TEWGraphicButtonWidget.h"
#include "TEWScrollBarTrack.h"
#include "TEWControlWidget.h"
#include "../Properties/Logical/Callback.h"
#pragma pack(push, 1)

/**
 * @brief Representation of the game TEWScrollBar structure.
 */
class TEWScrollBar : public TEWControlWidget
{
public:
	TEWScrollBar(TLBSWidget* Parent, Border Border, Callback Callback,TEWScrollBarTrack* Scroller, TEWGraphicButtonWidget* ButtonScrollTop, TEWGraphicButtonWidget* ButtonScrollBot)
		: TEWControlWidget(ClassSearcher::GetClassInfoFromName("TEWScrollBar").GetVTable()
		, 0x01, Parent, nullptr, Border)
		, scroller(Scroller)
		, buttonScrollBotWidget(ButtonScrollBot)
		, buttonScrollTopWidget(ButtonScrollTop)
		, callback(Callback)
	{
		unknown13 = 1;
		addWidget(scroller);
		addWidget(buttonScrollTopWidget);
		addWidget(buttonScrollBotWidget);
	}

private:
	TEWScrollBarTrack* scroller;					// 0x68 @TODO Class
	TEWGraphicButtonWidget* buttonScrollTopWidget;	// 0x6C
	TEWGraphicButtonWidget* buttonScrollBotWidget;	// 0x70
	int32_t unknown13;								// 0x74 if 0, the scrollbar is white, else it applies the style
	Callback callback;								// 0x78 eax is equal to parent, and ecx to index of scroll (0 top, 1 scrolled once, etc)
};
static_assert(sizeof(TEWScrollBar) == 0x80, "TEWScrollBar does not have a size of 0x80.");

#pragma pack(pop)