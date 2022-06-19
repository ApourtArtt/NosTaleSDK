#pragma once
#include "ArmorConfig.h"

EffectId defaultNoEffect = 0;

upgradeToEffectId defaultSubLegendaryArmorEffect =
{
	{ 0, defaultNoEffect },
	{ 1, 3034 },
	{ 2, 3025 },
	{ 3, 3026 },
	{ 4, 3027 },
	{ 5, 3028 },
	{ 6, 3029 },
	{ 7, 3030 },
	{ 8, 3031 },
	{ 9, 3032 },
	{ 10, 3002 },
};

upgradeToEffectId defaultAboveLegendaryArmorEffect =
{

	{ 0, defaultNoEffect },
	{ 1, 3034 },
	{ 2, 3000 },
	{ 3, 3000 },
	{ 4, 3000 },
	{ 5, 3001 },
	{ 6, 3001 },
	{ 7, 3001 },
	{ 8, 3033 },
	{ 9, 3033 },
	{ 10, 3035 },
};

effectsMap defaultArmorEffects =
{
	{ RarityType::DAMAGED,		defaultSubLegendaryArmorEffect },
	{ RarityType::LOW_LEVEL,	defaultSubLegendaryArmorEffect },
	{ RarityType::_,			defaultSubLegendaryArmorEffect },
	{ RarityType::USEFUL,		defaultSubLegendaryArmorEffect },
	{ RarityType::GOOD,			defaultSubLegendaryArmorEffect },
	{ RarityType::HIGH_QUALITY,	defaultSubLegendaryArmorEffect },
	{ RarityType::EXCELLENT,	defaultSubLegendaryArmorEffect },
	{ RarityType::ANCIENT,		defaultSubLegendaryArmorEffect },
	{ RarityType::MYSTERIOUS,	defaultSubLegendaryArmorEffect },
	{ RarityType::LEGENDARY,	defaultAboveLegendaryArmorEffect },
	{ RarityType::PHENOMENAL,	defaultAboveLegendaryArmorEffect },
};
