#pragma once
#include "TEWCustomFormWidget.h"
#include "TNTTimeAniIcon.h"
#pragma pack(push, 1)

// TODO: Deep reverse

/**
 * @brief Represents the game TNTNewCharacterSkillInfoWidget.
 */
class TNTNewCharacterSkillInfoWidget : public TEWCustomFormWidget
{
public:
	char pad_00BC[52]; //0x00BC
	TNTTimeAniIcon* aSlotsAniIcons[24]; //0x00F0
	char pad_0150[148]; //0x0150
}; //Size: 0x01E4
static_assert(sizeof(TNTNewCharacterSkillInfoWidget) == 0x1E4);

#pragma pack(pop)
