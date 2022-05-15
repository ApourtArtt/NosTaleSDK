#pragma once
#include "../../DelphiClasses/TNTIconWidget.h"

/**
 * @brief Game data representation of the partner resistance icons.
 */
class PartnerResistanceIcons
{
public:
	TNTIconWidget* glovesIcon; //0x0000
	TNTIconWidget* shoesIcon; //0x0004
}; //Size: 0x0008
static_assert(sizeof(PartnerResistanceIcons) == 0x8, "PartnerResistanceIcons does not have a size of 0x8");