#include "ConnectionManager.h"
#include "../../../Utils/Logger.h"

ConnectionManager::ConnectionManager(const ConnectionManagerConfig& Config) noexcept
	: Manager(Config, "ConnectionManager")
	, servChanMng(Config.ServChanConfig)
{}

bool ConnectionManager::initialize() noexcept
{
	if (!servChanMng.Initialize())
		return false;

	Logger::Success("Successfully initialized");
	return true;
}

bool ConnectionManager::unload() noexcept
{
	bool res = true;

	if (!servChanMng.Unload())
		res = false;

	return res;
}

void ConnectionManager::tick() noexcept
{
	servChanMng.Tick();
}
