#pragma once
#include "SpManager/SpConfig.h"
#include "WeaponManager/WeaponConfig.h"
#include "StuffRarityManager/StuffRarityConfig.h"

struct StuffManagerConfig
{
	WeaponManagerConfig WeaponConfig;
	SpManagerConfig SpConfig;
	StuffRarityManagerConfig StuffRarityConfig;
};
