#pragma once
#include <map>
#include "../../../../Properties/Graphical/TextStyle.h"
#include "../../../../Enums/RarityType.h"

typedef std::map<RarityType, TextStyle> rarityToTextStyle;
typedef std::map<RarityType, int32_t> rarityToTextVnum;

struct StuffRarityManagerConfig
{
	rarityToTextStyle AdditionalRarityTextStyle;
	rarityToTextVnum AdditionalRarityTextVnum;
};
