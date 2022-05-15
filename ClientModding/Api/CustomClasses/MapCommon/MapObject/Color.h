#pragma once
#include "../../../../MemoryHelper/PatternScan.h"
#include "../../../../Utils/Logger.h"

/**
 * @brief Represents the game color used for all the objects.
 */
class Color
{
public:
	Color();

	void SetRed(float Red);
	void SetGreen(float Green);
	void SetBlue(float Blue);

	void SetRedDelta(float Red);
	void SetGreenDelta(float Green);
	void SetBlueDelta(float Blue);

private:
	uintptr_t GetAddress();

	uintptr_t address; ///< Game address where the Color structure is located.
};
