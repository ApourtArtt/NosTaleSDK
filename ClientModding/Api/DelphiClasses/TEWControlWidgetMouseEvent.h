#pragma once
#include "TEWControlWidget.h"
#pragma pack(push, 1)

class TEWControlWidgetMouseEvent : public TEWControlWidget
{
public:
	static constexpr std::string_view NAME = "TEWControlWidgetMouseEvent";

protected:
	char unknown13[0x40]; // 0x68
};
static_assert(sizeof(TEWControlWidgetMouseEvent) == 0xA8, "TEWControlWidgetMouseEvent does not have a size of 0xA8.");

#pragma pack(pop)
