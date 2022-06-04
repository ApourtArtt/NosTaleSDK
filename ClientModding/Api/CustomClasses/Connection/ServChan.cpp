#include "ServChan.h"
#include "../../../Utils/Logger.h"

bool ServChan::Initialize()
{
	auto _ = Logger::PushPopModuleName("Connection");

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

	return true;
}

short ServChan::GetServer() const
{
	return (*(uintptr_t*)address & 0xff);
}

short ServChan::GetChannel() const
{
	return ((*(uintptr_t*)address >> 0x10) & 0xff);
}
