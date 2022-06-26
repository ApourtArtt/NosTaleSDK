#include "NpcTalkRangeManager.h"
#include "../../../../../MemoryHelper/PatternScan.h"
#include "../../../../../MemoryHelper/Patch.h"
#include "../../../../DelphiClasses/TPlayerObjManager.h"

NpcTalkRangeManager::NpcTalkRangeManager(const NpcTalkRangeManagerConfig& Config) noexcept
	: Manager(Config, "NpcTalkRangeManager")
{}

bool NpcTalkRangeManager::initialize() noexcept
{
	auto patternDefaultRange = PatternScan(
		"\x8b\x00\x66\xc7\x00\x00\x01\x00\xa1\x00\x00\x00\x00\x8b\x00\x66\xc7\x00\x00\x03\x00\xa1\x00\x00\x00\x00",
		"x?xx??xxx????x?xx??xxx????", 19
	);
	if (patternDefaultRange == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("patternDefaultRange = %x", patternDefaultRange);

	Patch((BYTE*)patternDefaultRange, (BYTE*)&config.DefaultTalkRange, 2);

	Logger::Success("Successfully initialized");
	return true;
}

bool NpcTalkRangeManager::unload() noexcept
{
	return false; // TODO
}

void NpcTalkRangeManager::tick() noexcept
{}

void NpcTalkRangeManager::SetCurrentRange(int16_t Range) noexcept
{
	TPlayerObjManager::getNtInstance()->setNpcTalkRange(Range);
}
