#pragma once
#include "../../../../Enums/RarityType.h"
#include <map>

typedef int8_t Upgrade;
typedef int32_t EffectId;
typedef std::map<Upgrade, EffectId> upgradeToEffectId;
typedef std::map<RarityType, upgradeToEffectId> effectsMap;

struct ArmorManagerConfig
{
	effectsMap AdditionalEffects;
};
