#include "MapCommon.h"

bool MapCommon::Initialize()
{
	if (!color.Initialize())
		return false;
	if (!fog.Initialize())
		return false;
	return true;
}
