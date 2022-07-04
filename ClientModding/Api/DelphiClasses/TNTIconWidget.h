#pragma once
#include "TEWControlWidgetEvent.h"
#include "../Properties/Graphical/Border.h"
#include "../Properties/Graphical/IconProperties.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
* Find ImageProperties real structure
* 0x78, 0x90, 0x98 are callbacks
*/

class TNTIconWidget : public TEWControlWidgetEvent
{
public:
	explicit TNTIconWidget() {} // Allows deep copy

	TNTIconWidget(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWControlWidgetEvent(VTable, EvenThing, Parent, Childs, Border)
	{}

	TNTIconWidget(TLBSWidget* Parent, Border Border, int16_t Vnum, int16_t Unknown17)
		: TEWControlWidgetEvent(ClassSearcher::GetClassInfoFromName("TNTIconWidget").GetVTable()
		, 0x1, Parent, nullptr, Border)
		, unknown17(Unknown17)
	{
		image = new IconProperties(Vnum);

		keepTransparency = true;
	}

	void setSlot(int16_t Slot) noexcept { slot = Slot; }
	void setIconProperties(IconProperties* IconProperties) noexcept { image = IconProperties; }

	IconProperties* getIconProperties() noexcept { return image; }

protected:
	bool showEdgesInblue;	// 0x70
	char unknown14[15];		// 0x71
	int16_t clickX;			// 0x80
	int16_t clickY;			// 0x82
	bool keepTransparency;	// 0x84
	bool resized;			// 0x85 Weird behaviour, what is it really ?
	char unknown16[26];		// 0x86
	/*
	0x98 : callback doubleleft  click
	*/
	char unknown17;			// 0xA0 5 for my turtle, other value = transparent. 1 on my sheep change to something animated.
	bool showEdgesInOrange;	// 0xA1
	char unknown18;			// 0xA2
	bool animate;			// 0xA3
	char unknown19[4];		// 0xA4
	IconProperties* image;	// 0xA8
	char unknown20[4];		// 0xAC
	int16_t slot;			// 0xB0
	char unknown21[26];		// 0xB2
};
static_assert(sizeof(TNTIconWidget) == 0xCC, "TNTIconWidget does not have a size of 0xCC.");

#pragma pack(pop)
