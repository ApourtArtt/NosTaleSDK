#pragma once
#include "../../../Manager.h"
#include "StuffRarityConfig.h"

class StuffRarityManager : public Manager<StuffRarityManagerConfig>
{
public:
	[[nodiscard]] explicit StuffRarityManager(const StuffRarityManagerConfig& Config) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	[[nodiscard]] bool initializeRarityTextStyleDisplay() noexcept;
	[[nodiscard]] bool initializeRarityTextDisplayHover() noexcept;
	[[nodiscard]] bool initializeRarityTextDisplaySheet() noexcept;
};
