#pragma once
#include "../../DelphiClasses/TEWGraphicButtonWidget.h"

/**
 * @brief Game data representation of the partner sp automatic buttons.
 */
class PartnerSkillsAutomaticButtons
{
public:
	TEWGraphicButtonWidget* firstButton; //0x0000
	TEWGraphicButtonWidget* secondButton; //0x0004
	TEWGraphicButtonWidget* thirdButton; //0x0008
}; //Size: 0x000C
static_assert(sizeof(PartnerSkillsAutomaticButtons) == 0xC, "PartnerSkillsAutomaticButtons does not have a size of 0xC");