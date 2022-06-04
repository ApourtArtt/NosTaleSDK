#include "UIManager.h"
#include "../../../Utils/Logger.h"

UIManager::UIManager(const UIManagerConfig& Config)
	: spyHpMpMng(Config.SpyHpMpConfig)
{
}

bool UIManager::Initialize()
{
	auto _ = Logger::PushPopModuleName("UIManager");

	if (!spyHpMpMng.Initialize())
		return false;

	Logger::Success("Successfully initialized");
	return true;
}
