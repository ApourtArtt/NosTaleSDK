#pragma once
#include "SpyHpMpConfig.h"

class SpyHpMpManager
{
public:
	SpyHpMpManager(const SpHpMpManagerConfig& Config);
	[[nodiscard]] bool Initialize();

private:
	SpHpMpManagerConfig config;
};
