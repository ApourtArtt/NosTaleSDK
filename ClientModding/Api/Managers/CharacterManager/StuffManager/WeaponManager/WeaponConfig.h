#pragma once
#include "../../../../Properties/Graphical/WeaponGlowingStyle.h"

typedef std::map<Upgrade, WeaponGlow> upgradeToGlow;
typedef std::map<Rarity, upgradeToGlow> glowsMap;

struct WeaponManagerConfig
{
	glowsMap AdditionalWeaponsGlow;
};
