#pragma once
#include "WingsConfig.h"

class WingsManager
{
public:
	explicit WingsManager(const WingsManagerConfig& Config);
	bool Initialize();

private:
	WingsManagerConfig config;
};
