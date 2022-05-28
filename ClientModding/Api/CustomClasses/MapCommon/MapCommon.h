#pragma once
#include "Fog.h"
#include "MapObject/Color.h"

/**
 * @brief Holds map related classes.
 */
class MapCommon
{
public:
	[[nodiscard]] bool Initialize();

	Fog fog;
	Color color;

private:
};
