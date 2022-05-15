#pragma once
#include "../../../DelphiClasses/TNTNewCharacterSkillInfoWidget.h"
#include "../../../DelphiClasses/TEWLabel.h"
#include <map>

/**
 * @brief Singleton wrapper around the game TNTNewCharacterSkillInfoWidget structure.
 */
class NewCharacterSkillInfoWidget
{
public:
	NewCharacterSkillInfoWidget(NewCharacterSkillInfoWidget& other) = delete;
	void operator=(const NewCharacterSkillInfoWidget& other) = delete;
	static NewCharacterSkillInfoWidget& getInstance();

	const DWORD getTNTNewCharacterSkillInfoWidgetAddress() const;
	TEWLabel* getCooldownLabel(TNTTimeAniIcon* icon);

private:
	NewCharacterSkillInfoWidget();
	void getAddresses();
	void addCooldownLabels();

private:
	TNTNewCharacterSkillInfoWidget* newCharacterSkillInfoWidget;
	std::map <TNTTimeAniIcon*, TEWLabel*> cooldownLabels;
};
