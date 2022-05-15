#pragma once
#include "../../../MemoryHelper/PatternScan.h"
#include "../../../MemoryHelper/Patch.h"
#include "../Wrappers/Widgets/NewCharacterStandardInfoWidget.h"
#include <vector>

/**
 * TODO: If game is using 32 bit in the game settings and you untick the "window mode"
 * when you try to change a resolution using our custom widget it breaks the resolution
 * and it looks very weird. I took a look and it seems like the function in this scenario is called 2 times,
 * one for setting the "full screen" mode and another one to set the actual resolution.
 * 
 * So we need to fix this or maybe add our own callback to the "window mode" button to avoid this.
 */

struct ScreenResolution
{
public:
	int x;
	int y;

	ScreenResolution(int X, int Y) : x(X), y(Y) {}
};

/**
 * @brief Represents the game WindowBase structure.
 */
class WindowBase
{
public:
	int uknown;
	int x; ///< Resolution width
	int y; ///< Resolution heigh
};

/**
 * @brief Wrapper around the WindowBase structure.
 */
class Resolution
{
public:
	Resolution();

	/**
	 * @brief Change resolution depending on the resolutionID.
	 * @param resolutionID the index of the resolution we want to set.
	 */
	void SetResolution(int resolutionID);

private:
	void getAddresses();

	DWORD funcAddy;
	DWORD checkAddress;
	DWORD hookAddy;
	DWORD TGameRootWidgetPtr;
};
