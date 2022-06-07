#pragma once
#include "TEWCustomPanelWidget.h"
#include "TEWLabel.h"
#include "TNTMaskingGaugeWidget.h"
#include "TNTItemList.h"
#include "TEWGraphicButtonWidget.h"
#include "TNTIconWidget.h"
#pragma pack(push, 1)

class TNTPartySummaryInfoWidget : public TEWCustomPanelWidget
{
public:
	static constexpr std::string_view NAME = "TNTPartySummaryInfoWidget";

private:
	// TODO: offset are not fix, need to handle it another way
	char unknown19[4]; // 0xA4
	TEWLabel* labelLevel; // 0xA8
	TEWLabel* labelPseudonym; // 0xAC
	TNTMaskingGaugeWidget* gaugeHp; // 0xB0
	TNTMaskingGaugeWidget* gaugeMp; // 0xB4
	TNTItemList* itemListUnknown; // 0xB8
	char unknown20[4]; // 0xBC
	void* TPetSelectIcon; // 0xC0 (pet image)
	TEWControlWidgetEX* greenCircle; // 0xC4
	TEWControlWidgetEX* topLeftImage; // 0xC8
	TEWControlWidgetEX* bottomLeftImageRemoved; // 0xCC
	char unknown21[4]; // 0xD0 triggered on click
	TEWControlWidgetEX* bottomLeftImage; // 0xD4
	TEWGraphicButtonWidget* topRightButton; // 0xD8
	char unknown22[4]; // 0xDC
	char unknown23[4]; // 0xE0
	char unknown24[4]; // 0xE4
	char unknown25[4]; // 0xE8
	TNTIconWidget* buff1; // 0xEC
	TNTIconWidget* buff2; // 0xF0
	TNTIconWidget* buff3; // 0xF4
	TNTIconWidget* buff4; // 0xF8
	TNTIconWidget* buff5; // 0xFC
	TNTIconWidget* buff6; // 0x100
	TNTIconWidget* buff7; // 0x104
	TNTIconWidget* buff8; // 0x108
	char unknown26[4]; // 0x10C
	void* TNTGraphicButtonAtSpecialCard; // 0x110 SP button
};
static_assert(sizeof(TNTPartySummaryInfoWidget) == 0x114, "TNTPartySummaryInfoWidget does not have a size of 0x114");

#pragma pack(pop)
