#include "../../../Utils/Logger.h"
#include "MapManager.h"


MapManager::MapManager(const MapManagerConfig& Config) noexcept
	: Manager(Config, "MapManager")
	, colorMng(Config.ColorConfig)
{}

bool MapManager::initialize() noexcept
{
	if (!colorMng.Initialize())
		return false;

	Logger::Success("Successfully initialized");
	return true;
}

bool MapManager::unload() noexcept
{
	bool res = true;

	if (!colorMng.Unload())
		res = false;

	return res;
}

void MapManager::tick() noexcept
{
	colorMng.Tick();
}
