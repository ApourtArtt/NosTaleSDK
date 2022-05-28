#pragma once
#include "../../../../MemoryHelper/PatternScan.h"
#include "../../../../Utils/Logger.h"

/**
 * @brief Represents the game color used for all the objects.
 */
class Color
{
public:
	[[nodiscard]] bool Initialize();

	void SetRed(float Red);
	void SetGreen(float Green);
	void SetBlue(float Blue);

	void SetRedDelta(float Red);
	void SetGreenDelta(float Green);
	void SetBlueDelta(float Blue);

private:
	uintptr_t address;
};
