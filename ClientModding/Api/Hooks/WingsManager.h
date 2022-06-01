#pragma once
#include "../../MemoryHelper/TrampolineHook.h"

class WingsManager
{
public:
	bool Initialize();

private:
	TrampolineHook* trmpHook;
};
