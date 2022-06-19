#include "StuffManager.h"

StuffManager::StuffManager(const StuffManagerConfig& Config) noexcept
	: Manager(Config, "StuffManager")
	, spMng(Config.SpConfig)
	, weaponMng(Config.WeaponConfig)
	, stuffRarityMng(Config.StuffRarityConfig)
	, armorMng(Config.ArmorConfig)
{}

bool StuffManager::initialize() noexcept
{
	if (!spMng.Initialize())
		return false;
	if (!weaponMng.Initialize())
		return false;
	if (!stuffRarityMng.Initialize())
		return false;
	if (!armorMng.Initialize())
		return false;
	
	return true;
}

bool StuffManager::unload() noexcept
{
	bool res = true;

	if (!spMng.Unload())
		res = false;
	if (!weaponMng.Unload())
		res = false;
	if (!stuffRarityMng.Unload())
		res = false;
	if (!armorMng.Unload())
		res = false;

	return res;
}

void StuffManager::tick() noexcept
{
	spMng.Tick();
	weaponMng.Tick();
	stuffRarityMng.Tick();
	armorMng.Tick();
}
