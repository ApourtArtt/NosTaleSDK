#pragma once
#include "../../../MemoryHelper/PatternScan.h"

/**
 * @brief Represents the game server-channel structure.
 */
class ServChan
{
public:
	ServChan();

	short GetServer() const;
	short GetChannel() const;

private:
	uintptr_t address; ///< Game address to find server and channel values
};