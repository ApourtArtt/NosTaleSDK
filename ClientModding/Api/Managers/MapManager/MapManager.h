#pragma once
#include "../Manager.h"
#include "MapConfig.h"
#include "ColorManager/ColorManager.h"

class MapManager : public Manager<MapManagerConfig>
{
public:
	[[nodiscard]] explicit MapManager(const MapManagerConfig& Config) noexcept;

	[[nodiscard]] ColorManager& GetColorManager() noexcept { return colorMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	ColorManager colorMng;
};
