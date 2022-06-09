#pragma once
#include "../../../Manager.h"
#include "SpConfig.h"
#include "AuraManager/AuraManager.h"
#include "WingManager/WingManager.h"

class SpManager : public Manager<SpManagerConfig>
{
public:
	[[nodiscard]] explicit SpManager(const SpManagerConfig& Config) noexcept;

	[[nodiscard]] AuraManager& GetAuraManager() noexcept { return auraMng; }
	[[nodiscard]] WingManager& GetWingManager() noexcept { return wingMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	AuraManager auraMng;
	WingManager wingMng;
};

