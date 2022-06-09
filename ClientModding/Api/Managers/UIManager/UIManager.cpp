#include "UIManager.h"

UIManager::UIManager(const UIManagerConfig& Config) noexcept
	: Manager(Config, "UIManager")
	, spyHpMpMng(Config.SpyHpMpConfig)
	, idleMng(Config.IdleConfig)
{}

bool UIManager::initialize() noexcept
{
	if (!spyHpMpMng.Initialize())
		return false;
	if (!idleMng.Initialize())
		return false;

	Logger::Success("Successfully initialized");
	return true;
}

bool UIManager::unload() noexcept
{
	bool res = true;

	if (!spyHpMpMng.Unload())
		res = false;
	if (!idleMng.Unload())
		res = false;

	return res;
}

void UIManager::tick() noexcept
{
	spyHpMpMng.Tick();
	idleMng.Tick();
}
