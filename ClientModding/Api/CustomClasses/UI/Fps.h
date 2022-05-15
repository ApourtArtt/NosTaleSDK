#pragma once
#include "../../../MemoryHelper/PatternScan.h"
#include <stdio.h>

/**
 * @brief Wrapper around the sleep value in the main game loop.
 * This class allows us to modify the game fps limit.
 */
class Fps
{
public:
	Fps();

	/**
	 * @brief Directly change the sleep value to RefreshRate.
	 * @param RefreshRate the new sleep value
	 */
	void SetRefreshRate(int RefreshRate);

	/**
	 * @brief Change FPS limit value.
	 * @param Fps new limit
	 */
	void SetFps(int Fps);

private:
	uintptr_t GetAddress();

	uintptr_t address; ///< Game address where the sleep value is located.
};
