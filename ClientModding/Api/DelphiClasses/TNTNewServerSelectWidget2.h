#pragma once
#include "TEWControlWidgetEX.h"
#pragma pack(push, 1)

class TNTNewServerSelectWidget2 : public TEWControlWidgetEX
{
public:
	static constexpr std::string_view NAME = "TNTNewServerSelectWidget2";

	TEWControlWidgetEX* getServerTrackerWidget() { return serverTrackerWidget; }

protected:
	char unknown13[0x18];
	TEWControlWidgetEX* serverTrackerWidget;
	char unknown14[0x1E0];
};
static_assert(sizeof(TNTNewServerSelectWidget2) == 0x264, "TNTNewServerSelectWidget2 does not have a size of 0x264.");

#pragma pack(pop)
