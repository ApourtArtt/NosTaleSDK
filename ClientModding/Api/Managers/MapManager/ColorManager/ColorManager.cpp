#include "ColorManager.h"
#include "../../../../MemoryHelper/PatternScan.h"

ColorManager::ColorManager(const ColorManagerConfig& Config) noexcept
	: Manager(Config, "ColorManager")
{}

bool ColorManager::initialize() noexcept
{
	if (!initializeFog())
		return false;
	if (!initializeObject())
		return false;

	Logger::Success("Successfully initialized");
	return true;
}

bool ColorManager::unload() noexcept
{
	return true;
}

void ColorManager::tick() noexcept
{}

bool ColorManager::initializeFog() noexcept
{
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

	fogAddress = *(uintptr_t*)patternAddr;
	if (fogAddress == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("fogAddress = %x", fogAddress);

	fogAddress = *(uintptr_t*)fogAddress;
	if (fogAddress == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("fogAddress = %x", fogAddress);

	return true;
}

bool ColorManager::initializeObject() noexcept
{
	auto patternAddr = PatternScan(
		"\xA5\xA5\xA5\xA5\x5F\x5E\xA1\x00\x00\x00\x00\x56\x57\x8B\xF7\x8D\x78\x04\xA5\xA5\xA5\xA5\x5F\x5E",
		"xxxxxxx????xxxxxxxxxxxxx", 7
	);
	if (patternAddr == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("patternAddr = %x", patternAddr);

	objectAddress = *(uintptr_t*)patternAddr;
	if (objectAddress == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("objectAddress = %x", objectAddress);

	objectAddress = *(uintptr_t*)objectAddress;
	if (objectAddress == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("objectAddress = %x", objectAddress);

	return true;
}

void ColorManager::SetFirstFogIntensity(float Value) noexcept
{
	*(float*)(fogAddress + 0x08) = Value;
}

void ColorManager::SetSecondFogIntensity(float Value) noexcept
{
	*(float*)(fogAddress + 0x0C) = Value;
}

void ColorManager::SetFogBlue(uint8_t Blue) noexcept
{
	*(uint8_t*)(fogAddress + 0x00) = Blue;
}

void ColorManager::SetFogGreen(uint8_t Green) noexcept
{
	*(uint8_t*)(fogAddress + 0x01) = Green;
}

void ColorManager::SetFogRed(uint8_t Red) noexcept
{
	*(uint8_t*)(fogAddress + 0x02) = Red;
}

void ColorManager::SetObjectRed(float Red) noexcept
{
	*(float*)(objectAddress + 0x04) = Red;
}

void ColorManager::SetObjectGreen(float Green) noexcept
{
	*(float*)(objectAddress + 0x08) = Green;
}

void ColorManager::SetObjectBlue(float Blue) noexcept
{
	*(float*)(objectAddress + 0x0C) = Blue;
}

void ColorManager::SetObjectRedDelta(float Red) noexcept
{
	*(float*)(objectAddress + 0x24) = Red;
}

void ColorManager::SetObjectGreenDelta(float Green) noexcept
{
	*(float*)(objectAddress + 0x28) = Green;
}

void ColorManager::SetObjectBlueDelta(float Blue) noexcept
{
	*(float*)(objectAddress + 0x2C) = Blue;
}
