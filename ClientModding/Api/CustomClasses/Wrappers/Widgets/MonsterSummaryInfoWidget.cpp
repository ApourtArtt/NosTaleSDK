#include "MonsterSummaryInfoWidget.h"
#include "../../../../MemoryHelper/PatternScan.h"
#include "../../../../Utils/Logger.h"

namespace
{
	constexpr int GENERAL_OFFSET = 40;
	constexpr int PANEL_OFFSET = 30;
	constexpr int PANEL_INCREASE = 10;
	constexpr int LEVEL_LABEL_OFFSET = 60;

	constexpr int MENU_BUTTONS_SIZE = 9;

	constexpr int OLD_HEAD_INDEX = 3;
	constexpr int TYPE_CONTROL_INDEX = 7;
	constexpr int ELEMENT_CONTROL_INDEX = 9;
	constexpr int CAPTURE_CONTROL_INDEX = 11;
	constexpr int OTHER_CONTROL_INDEX = 13;
}

MonsterSummaryInfoWidget& MonsterSummaryInfoWidget::getInstance()
{
	static MonsterSummaryInfoWidget instance;
	return instance;
}

MonsterSummaryInfoWidget::MonsterSummaryInfoWidget()
{
	getAddresses();
	makeBeautiful();
}

void MonsterSummaryInfoWidget::getAddresses()
{
	auto address = PatternScan(
		"\x8b\x15\x00\x00\x00\x00\x8b\x12\x89\x82\x00\x00\x00\x00\x8b\xc3",
		"xx????xxxx????xx",
		2
	);

	if (!address)
	{
		Logger::log("Error on TNTMonsterSummaryInfoWidget pattern scan.\n");
		monsterSummaryInfoWidget = nullptr;
		return;
	}

	monsterSummaryInfoWidget = ***(TNTMonsterSummaryInfoWidget****)address;
}

void MonsterSummaryInfoWidget::makeBeautiful()
{
	if (!monsterSummaryInfoWidget) return;

	monsterSummaryInfoWidget->oldHeadCircle->setVisible(true);
	monsterSummaryInfoWidget->oldHeadIcon->setVisible(true);
	monsterSummaryInfoWidget->getChilds().get_item_at_index(3)->setVisible(true); // Old head background

	TEWCustomPanelWidget* hpBar = (TEWCustomPanelWidget*)monsterSummaryInfoWidget->healthBar;
	TEWCustomPanelWidget* mpBar = (TEWCustomPanelWidget*)monsterSummaryInfoWidget->manaBar;

	// Increase main widget
	monsterSummaryInfoWidget->incrementSize(GENERAL_OFFSET, 0);

	// Move panel to the right and increase size
	monsterSummaryInfoWidget->widgetPanel->moveWidget(PANEL_OFFSET, 0);
	monsterSummaryInfoWidget->widgetPanel->incrementSize(PANEL_INCREASE, 0);
	
	// Move widgets to the right
	hpBar->moveWidget(GENERAL_OFFSET, 0);
	mpBar->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->levelLabel->moveWidget(LEVEL_LABEL_OFFSET, 0);
	monsterSummaryInfoWidget->nameLabel->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->entityTypeIcon->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->elementIcon->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->isCapturableIcon->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->displayMenuButton->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->closeButton->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->getChilds().get_item_at_index(TYPE_CONTROL_INDEX)->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->getChilds().get_item_at_index(ELEMENT_CONTROL_INDEX)->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->getChilds().get_item_at_index(CAPTURE_CONTROL_INDEX)->moveWidget(GENERAL_OFFSET, 0);
	monsterSummaryInfoWidget->getChilds().get_item_at_index(OTHER_CONTROL_INDEX)->moveWidget(GENERAL_OFFSET, 0);

	// Move the menu buttons
	for (int i = 0; i < MENU_BUTTONS_SIZE; i++)
	{
		TEWButtonWidget* button = *(TEWButtonWidget**)((DWORD)&monsterSummaryInfoWidget->partyButton + i * 4);
		if (!button) continue;
		button->moveWidget(GENERAL_OFFSET, 0);
	}
}
