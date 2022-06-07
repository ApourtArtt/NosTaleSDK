#include "NewCharacterSkillInfoWidget.h"
#include "../../../../MemoryHelper/PatternScan.h"

NewCharacterSkillInfoWidget& NewCharacterSkillInfoWidget::getInstance()
{
	static NewCharacterSkillInfoWidget instance;
	return instance;
}

const DWORD NewCharacterSkillInfoWidget::getTNTNewCharacterSkillInfoWidgetAddress() const
{
	return (DWORD)newCharacterSkillInfoWidget;
}

TEWLabel* NewCharacterSkillInfoWidget::getCooldownLabel(TNTTimeAniIcon* icon)
{
	if (!newCharacterSkillInfoWidget) return nullptr;
	return cooldownLabels[icon];
}

NewCharacterSkillInfoWidget::NewCharacterSkillInfoWidget()
{
	getAddresses();
	addCooldownLabels();
}

void NewCharacterSkillInfoWidget::getAddresses()
{
	auto address = PatternScan(
		"\xa1\x00\x00\x00\x00\x8b\x00\x8b\x80\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x89\x45\x00\x8b\x45\x00\x83\x38\x00\x0f\x84",
		"x????xxxx????x????xx?xx?xx?xx",
		1
	);

	if (!address)
	{
		newCharacterSkillInfoWidget = nullptr;
		return;
	}

	newCharacterSkillInfoWidget = ***(TNTNewCharacterSkillInfoWidget****)address;
}

void NewCharacterSkillInfoWidget::addCooldownLabels()
{
	if (!newCharacterSkillInfoWidget) return;

	for (int i = 0; i < 24; i++)
	{
		TNTTimeAniIcon* icon = newCharacterSkillInfoWidget->aSlotsAniIcons[i];
		TEWLabel* label = new TEWLabel(
			icon,
			Border(4, 13, 40, 40),
			TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(255, 255, 255, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
			TextPosition(1, 1, 30, 16, new WString(L"00:00"), true)
		);

		icon->addWidget(label);
		cooldownLabels.emplace(icon, label);
	}
}
