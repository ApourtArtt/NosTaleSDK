#pragma once
#include "../../../DelphiClasses/TNTQuickSlotWidget.h"
#include "../../../DelphiClasses/TEWLabel.h"
#include <vector>
#include <map>

/**
 * @brief Singleton wrapper around the game TNTQuickSlotWidget structure.
 */
class QuickSlotWidget
{
public:
	QuickSlotWidget(QuickSlotWidget& other) = delete;
	void operator=(const QuickSlotWidget& other) = delete;
	static QuickSlotWidget& getInstance();

	TNTTimeAniIcon* getAniIconWidget(int index);
	TEWLabel* getCooldownLabel(TNTTimeAniIcon* icon);
	const DWORD getTNTQuickSlotWidgetAddress() const;

private:
	QuickSlotWidget();
	void getAddress();
	void addCooldownLabels();

private:
	TNTQuickSlotWidget* quickSlotWidget;
	std::map <TNTTimeAniIcon*, TEWLabel*> cooldownLabels;
};
