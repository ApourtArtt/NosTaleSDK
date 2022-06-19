#pragma once
#include "SpManager/SpConfig.h"
#include "WeaponManager/WeaponConfig.h"
#include "StuffRarityManager/StuffRarityConfig.h"
#include "ArmorManager/ArmorConfig.h"

struct StuffManagerConfig
{
	WeaponManagerConfig WeaponConfig;
	SpManagerConfig SpConfig;
	StuffRarityManagerConfig StuffRarityConfig;
	ArmorManagerConfig ArmorConfig;
};
