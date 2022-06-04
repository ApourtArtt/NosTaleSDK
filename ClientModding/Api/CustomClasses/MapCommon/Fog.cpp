#include "Fog.h"
#include "../../../Utils/Logger.h"

bool Fog::Initialize()
{
	auto _ = Logger::PushPopModuleName("Fog");

	auto patternAddr = PatternScan(
		"\x80\x3D\x00\x00\x00\x00\x00\x74\x00\xA1\x00\x00\x00\x00\x8B\x00\x50\x6A",
		"xx????xx?x????xxxx", 10
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

void Fog::SetBlue(uint8_t Blue)
{
	*(uint8_t*)(address + 0x00) = Blue;
}

void Fog::SetGreen(uint8_t Green)
{
	*(uint8_t*)(address + 0x01) = Green;
}

void Fog::SetRed(uint8_t Red)
{
	*(uint8_t*)(address + 0x02) = Red;
}

void Fog::SetFirstFog(float Value)
{
	*(float*)(address + 0x08) = Value;
}

void Fog::SetSecondFog(float Value)
{
	*(float*)(address + 0x0C) = Value;
}
