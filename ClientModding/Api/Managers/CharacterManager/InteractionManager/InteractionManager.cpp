#include "InteractionManager.h"

InteractionManager::InteractionManager(const InteractionManagerConfig& Config) noexcept
	: Manager(Config, "InteractionManager")
	, npcTalkRangeMng(Config.NpcTalkRangeConfig)
{
}

bool InteractionManager::initialize() noexcept
{
	if (!npcTalkRangeMng.Initialize())
		return false;

	Logger::Success("Successfully initialized");
	return true;
}

bool InteractionManager::unload() noexcept
{
	bool res = true;

	if (!npcTalkRangeMng.Unload())
		res = false;

	return res;
}

void InteractionManager::tick() noexcept
{
	npcTalkRangeMng.Tick();
}
