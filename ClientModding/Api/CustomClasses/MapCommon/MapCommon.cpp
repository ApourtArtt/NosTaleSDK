#include "MapCommon.h"
#include "../../../Utils/Logger.h"

bool MapCommon::Initialize()
{
	auto _ = Logger::PushPopModuleName("MapCommon");

	if (!color.Initialize())
		return false;
	
	if (!fog.Initialize())
		return false;
	
	Logger::Success("Successfully initialized");
	return true;
}
