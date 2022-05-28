#pragma once
#include "../../../MemoryHelper/PatternScan.h"

/** 
* @brief Wrapper around the game Fog structure. This allows
* us to change the game fog as we want for example making
* day and night cycle.
*/
class Fog
{
public:
	[[nodiscard]] bool Initialize();

	void SetBlue(uint8_t Blue);
	void SetGreen(uint8_t Green);
	void SetRed(uint8_t Red);

	void SetFirstFog(float Value);
	void SetSecondFog(float Value);

private:
	uintptr_t address;
};