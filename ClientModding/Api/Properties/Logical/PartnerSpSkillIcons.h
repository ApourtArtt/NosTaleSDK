#pragma once
#include "../../DelphiClasses/TNTIconWidget.h"

/**
 * @brief Game data representation of the partner sp skills icons.
 */
class PartnerSpSkillIcons
{
public:
	TNTIconWidget* firstSkillIconWidget; //0x0000
	TNTIconWidget* secondSkillIconWidget; //0x0004
	TNTIconWidget* thirdSkillIconWidget; //0x0008
}; //Size: 0x000C
static_assert(sizeof(PartnerSpSkillIcons) == 0xC, "PartnerSpSkillIcons does not have a size of 0xC");

