#pragma once
#include "../../../MemoryHelper/PatternScan.h"

/**
 * @brief Represents the game server-channel structure.
 */
class ServChan
{
public:
	[[nodiscard]] bool Initialize();

	[[nodiscard]] short GetServer() const;
	[[nodiscard]] short GetChannel() const;

private:
	uintptr_t address;
};