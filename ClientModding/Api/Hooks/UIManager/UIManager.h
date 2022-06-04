#pragma once
#include "UIConfig.h"
#include "SpyHpMp/SpyHpMpManager.h"

class UIManager
{
public:
	explicit UIManager(const UIManagerConfig& Config);
	[[nodiscard]] bool Initialize();

	[[nodiscard]] SpyHpMpManager& GetSpyHpMpManager() { return spyHpMpMng; }

private:
	UIManagerConfig config;
	SpyHpMpManager spyHpMpMng;
};
