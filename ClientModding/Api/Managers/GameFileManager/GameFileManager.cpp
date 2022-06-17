#include "GameFileManager.h"

GameFileManager::GameFileManager(const GameFileManagerConfig& Config) noexcept
	: Manager(Config, "GameFileManager")
	, nscliMng(Config.NScliConfig)
{}

bool GameFileManager::initialize() noexcept
{
	if (!nscliMng.Initialize())
		return false;

	Logger::Success("Successfully initialized");
	return true;
}

bool GameFileManager::unload() noexcept
{
	bool res = true;

	if (!nscliMng.Unload())
		res = false;

	return res;
}

void GameFileManager::tick() noexcept
{
	nscliMng.Tick();
}
