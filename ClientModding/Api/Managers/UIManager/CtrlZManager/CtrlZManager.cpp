#include "CtrlZManager.h"
#include "../../../../MemoryHelper/PatternScan.h"
#include "../../../../MemoryHelper/Patch.h"

CtrlZManager::CtrlZManager(const CtrlZManagerConfig& Config) noexcept
	: Manager(Config, "CtrlZManager")
{}

bool CtrlZManager::initialize() noexcept
{
	if (!config.Activated)
	{
		Logger::Log("Not activated");
		return true;
	}

	auto pattern = PatternScan(
		"\x53\x8b\xda\xe8\x00\x00\x00\x00\x8b\x15\x00\x00\x00\x00\x8b\x12\x8b\x00\x00\x8b\x0d\x00\x00\x00\x00",
		"xxxx????xx????xxx??xx????", 16
	);
	if (pattern == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("pattern = %x", pattern);

	Patch((BYTE*)pattern, (BYTE*)"\x31\xD2\x90", 3);

	Logger::Success("Successfully initialized");
	return true;
}

bool CtrlZManager::unload() noexcept
{
	return false; //todo
}

void CtrlZManager::tick() noexcept
{}
