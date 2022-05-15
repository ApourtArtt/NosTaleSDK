#pragma once
#include "../../DelphiClasses/TNTIconWidget.h"

/**
 * @brief Game data representation of the partner sp skill level icons.
 */
class PartnerSpSkillLevel
{
public:
	TNTIconWidget* firstSkillLevel; //0x0000
	TNTIconWidget* secondSkillLevel; //0x0004
	TNTIconWidget* thirdSkillLevel; //0x0008
}; //Size: 0x000C
static_assert(sizeof(PartnerSpSkillLevel) == 0xC, "PartnerSpSkillLevel does not have a size of 0xC");