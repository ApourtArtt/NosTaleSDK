#pragma once
#include "StuffConfig.h"

class StuffManager
{
public:
	explicit StuffManager(const StuffManagerConfig& Config);
	bool Initialize();

private:
	StuffManagerConfig config;
};
