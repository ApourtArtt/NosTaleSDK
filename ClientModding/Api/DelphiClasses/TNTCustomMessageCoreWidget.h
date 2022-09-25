#pragma once
#include "TEWCustomFormWidget.h"
#pragma pack(push, 1)

class TNTCustomMessageCoreWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTCustomMessageCoreWidget";

private:
	char unknown20[4];		// 0xBC
	wchar_t* textDisplayed;	// 0xC0
	char unknown21[4];		// 0xC4

};
static_assert(sizeof(TNTCustomMessageCoreWidget) == 0xD0, "TNTCustomMessageCoreWidget does not have a size of 0xD0");
// 0xBC
#pragma pack(pop)