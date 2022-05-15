#pragma once
#include "../../DelphiClasses/TNTIconWidget.h"
#pragma pack(push, 1)

/**
 * @brief Game data representation of the partner equipment icons (weapon and armor).
 */
class PartnerEquipmentIcons
{
public:
	TNTIconWidget* weaponIcon; //0x0000
	TNTIconWidget* armorIcon; //0x0004
}; //Size: 0x0008
static_assert(sizeof(PartnerEquipmentIcons) == 0x8, "PartnerEquipmentIcons does not have a size of 0x8");

#pragma pack(pop)