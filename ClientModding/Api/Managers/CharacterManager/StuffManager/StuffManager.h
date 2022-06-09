#pragma once
#include "../../Manager.h"
#include "StuffConfig.h"
#include "SpManager/SpManager.h"
#include "WeaponManager/WeaponManager.h"

class StuffManager : public Manager<StuffManagerConfig>
{
public:
	[[nodiscard]] explicit StuffManager(const StuffManagerConfig& Config) noexcept;

	[[nodiscard]] SpManager& GetSpManager() noexcept { return spMng; }
	[[nodiscard]] WeaponManager& GetWeaponManager() noexcept { return weaponMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	SpManager spMng;
	WeaponManager weaponMng;
};

