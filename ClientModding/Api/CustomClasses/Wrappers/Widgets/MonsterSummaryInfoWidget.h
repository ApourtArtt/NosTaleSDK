#pragma once
#include "../../../DelphiClasses/TNTMonsterSummaryInfoWidget.h"

/**
 * @brief Singleton wrapper around the game TNTMonsterSummaryInfoWidget structure.
 */
class MonsterSummaryInfoWidget
{
public:
	MonsterSummaryInfoWidget(MonsterSummaryInfoWidget& other) = delete;
	void operator=(const MonsterSummaryInfoWidget& other) = delete;
	static MonsterSummaryInfoWidget& getInstance();

private:
	MonsterSummaryInfoWidget();
	void getAddresses();
	void makeBeautiful();

private:
	TNTMonsterSummaryInfoWidget* monsterSummaryInfoWidget;
};
