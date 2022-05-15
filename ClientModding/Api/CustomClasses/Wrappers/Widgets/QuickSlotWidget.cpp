#include "QuickSlotWidget.h"
#include "../../../../MemoryHelper/PatternScan.h"

QuickSlotWidget& QuickSlotWidget::getInstance()
{
	static QuickSlotWidget instance;
	return instance;
}

TNTTimeAniIcon* QuickSlotWidget::getAniIconWidget(int index)
{	
	if (!quickSlotWidget)
		return nullptr;

	return quickSlotWidget->aSlotsAniIcons[index];
}

TEWLabel* QuickSlotWidget::getCooldownLabel(TNTTimeAniIcon* icon)
{
	if (!quickSlotWidget) return nullptr;

	return cooldownLabels[icon];
}

const DWORD QuickSlotWidget::getTNTQuickSlotWidgetAddress() const
{
	return (DWORD)quickSlotWidget;
}

QuickSlotWidget::QuickSlotWidget()
{
	getAddress();
	addCooldownLabels();
}

void QuickSlotWidget::getAddress()
{
	auto address = PatternScan(
		"\xa1\x00\x00\x00\x00\x8b\x00\x8b\x13\xe8\x00\x00\x00\x00\xa1",
		"x????xxxxx????x",
		1
	);

	if (!address)
	{
		quickSlotWidget = nullptr;
		return;
	}

	quickSlotWidget = ***(TNTQuickSlotWidget****)address;
}

void QuickSlotWidget::addCooldownLabels()
{
	if (!quickSlotWidget) return;

	for (int i = 0; i < 30; i++)
	{
		TNTTimeAniIcon* icon = quickSlotWidget->aSlotsAniIcons[i];
		TEWLabel* label = new TEWLabel(
			icon,
			Border(4, 13, 40, 40),
			TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(255, 255, 255, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
			TextPosition(1, 1, 30, 16, new AString(L"00:00"), true)
		);

		icon->addWidget(label);
		
		cooldownLabels.emplace(icon, label);
	}
}
