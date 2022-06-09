#pragma once
#include "../../../Manager.h"
#include "WeaponConfig.h"

class WeaponManager : public Manager<WeaponManagerConfig>
{
public:
	[[nodiscard]] explicit WeaponManager(const WeaponManagerConfig& Config) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;
};

