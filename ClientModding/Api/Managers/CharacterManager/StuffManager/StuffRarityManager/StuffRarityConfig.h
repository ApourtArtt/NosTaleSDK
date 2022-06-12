#pragma once
#include <map>
#include "../../../../Properties/Graphical/TextStyle.h"
#include "../../../../Enums/RarityType.h"

typedef std::map<RarityType, TextStyle> rarityToTextStyle;

struct StuffRarityManagerConfig
{
	rarityToTextStyle AdditionalWeaponsRarityTextStyle;
};
