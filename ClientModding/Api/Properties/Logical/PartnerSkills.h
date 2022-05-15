#pragma once
#include "../../DelphiClasses/TNTIconWidget.h"

/**
 * @brief Game data representation of the partner skills icons.
 */
class PartnerSkills
{
public:
	TNTIconWidget* firstSkill; //0x0000
	TNTIconWidget* secondSkill; //0x0004
}; //Size: 0x0008
static_assert(sizeof(PartnerSkills) == 0x8, "PartnerSkills does not have a size of 0x8");