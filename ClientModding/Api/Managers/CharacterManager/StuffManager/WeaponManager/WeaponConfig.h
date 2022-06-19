#pragma once
#include "../../../../Properties/Graphical/TextStyle.h"
#include "../../../../Properties/Graphical/WeaponGlowingStyle.h"
#include "../../../../Enums/RarityType.h"

typedef std::map<Upgrade, WeaponGlow> upgradeToGlow;
typedef std::map<RarityType, upgradeToGlow> glowsMap;
typedef std::map<RarityType, TextStyle> rarityToTextStyle;

struct WeaponManagerConfig
{
	glowsMap AdditionalGlow;
};
