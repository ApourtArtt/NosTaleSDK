#include "ServChanManager.h"
#include "../../../../MemoryHelper/PatternScan.h"

ServChanManager::ServChanManager(const ServChanManagerConfig& Config) noexcept
	: Manager(Config, "ServChanManager")
{}

bool ServChanManager::initialize() noexcept
{
	auto patternAddr = PatternScan(
		"\xe8\x00\x00\x00\x00\x66\x8b\x00\x00\x8b\x15\x00\x00\x00\x00\x66\x89\x02\xa1\x00\x00\x00\x00\x8b\x00",
		"x????xx??xx????xxxx????xx", 11
	);
	if (patternAddr == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("patternAddr = %x", patternAddr);

	address = *(uintptr_t*)patternAddr;
	if (address == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("address = %x", address);

	address = *(uintptr_t*)address;
	if (address == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("address = %x", address);

	Logger::Success("Successfully initialized");
	return true;
}

bool ServChanManager::unload() noexcept
{
	return true;
}

void ServChanManager::tick() noexcept
{}

short ServChanManager::GetServer() noexcept
{
	return (*(uintptr_t*)address & 0xff);
}

short ServChanManager::GetChannel() noexcept
{
	return ((*(uintptr_t*)address >> 0x10) & 0xff);
}
