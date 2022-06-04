#include "SpyHpMpManager.h"
#include "../../../../Utils/Logger.h"

SpyHpMpManager::SpyHpMpManager(const SpHpMpManagerConfig& Config)
	: config(Config)
{
}

bool SpyHpMpManager::Initialize()
{
	auto _ = Logger::PushPopModuleName("SpyHpMpManager");

	Logger::Success("Successfully initialized");
	return true;
}
