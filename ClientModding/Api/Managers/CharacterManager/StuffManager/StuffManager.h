#pragma once
#include "../../Manager.h"
#include "StuffConfig.h"
#include "SpManager/SpManager.h"
#include "WeaponManager/WeaponManager.h"
#include "StuffRarityManager/StuffRarityManager.h"
#include "ArmorManager/ArmorManager.h"

class StuffManager : public Manager<StuffManagerConfig>
{
public:
	[[nodiscard]] explicit StuffManager(const StuffManagerConfig& Config) noexcept;

	[[nodiscard]] SpManager& GetSpManager() noexcept { return spMng; }
	[[nodiscard]] WeaponManager& GetWeaponManager() noexcept { return weaponMng; }
	[[nodiscard]] StuffRarityManager& GetStuffRarityManager() noexcept { return stuffRarityMng; }
	[[nodiscard]] ArmorManager& GetArmorManager() noexcept { return armorMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	SpManager spMng;
	WeaponManager weaponMng;
	StuffRarityManager stuffRarityMng;
	ArmorManager armorMng;
};
