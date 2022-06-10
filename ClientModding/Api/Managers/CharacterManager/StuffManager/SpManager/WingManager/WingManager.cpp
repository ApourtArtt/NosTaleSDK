#include "WingManager.h"
#include "DefaultWing.h"
#include "../../../../../../MemoryHelper/Patch.h"
#include "../../../../../../MemoryHelper/PatternScan.h"
#include "../../../../../DelphiClasses/TNTSpecialWingFx.h"

namespace
{
	uintptr_t jmpback;
	wingsMap wings = defaultWings;

	void __stdcall wingsDisplay(TNTSpecialWingFx* wing, wingStyleId style, wingLevel level)
	{
		//Logger::Log("wing: %x style: %d level:%d", wing, style, level);
		if (level == ARENA_WINNER_SKELETON_LEVEL)
		{
			wing->setWingStyle(ARENA_WINNER_SKELETON_ID);
			return;
		}
		else if (level == ARENA_WINNER_WINGS_LEVEL)
		{
			wing->setWingStyle(ARENA_WINNER_WINGS_ID);
			return;
		}

		if (wings.count(style) == 0 || wings[style].count(level) == 0)
		{
			wing->setWeirdCounter(-1);
			return;
		}

		wing->setWingStyle(wings[style][level]);
	}

	void __declspec(naked) hk_wingsDisplay() noexcept
	{
		__asm
		{
			pushad;
			pushfd;

			push ecx;
			push eax;
			push ebx;

			call wingsDisplay;

			popfd;
			popad;

			jmp jmpback;
		}
	}
}

WingManager::WingManager(const WingManagerConfig& Config) noexcept
	: Manager(Config, "WingManager")
{
	for (auto const& [k1, v1] : config.AdditionalWings)
	{
		if (wings.find(k1) == wings.end())
			wings.insert({ k1, v1 });
		else
		{
			for (auto const& [k2, v2] : v1)
			{
				if (wings[k1].find(k2) == wings[k1].end())
					wings[k1].insert({ k2, v2 });
				else
					wings[k1][k2] = v2;
			}
		}
	}
}

bool WingManager::initialize() noexcept
{
	auto patternAddrWings = PatternScan(
		"\x55\x8b\xec\x83\xc4\x00\x53\x84\xd2\x74\x00\x83\xc4\x00\xe8\x00\x00\x00\x00\x88\x40\x00\x8b\xd8\x8b\x40\x00\x8b\xd0\x83\xfa\x00",
		"xxxxx?xxxx?xx?x????x??xxx??xxxx?", 29
	);
	if (patternAddrWings == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("patternAddrWings = %x", patternAddrWings);

	if (!Hook((BYTE*)patternAddrWings, (BYTE*)hk_wingsDisplay, 9))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	jmpback = (uintptr_t)PatternScan("\x6a\xff\x33\xc9\x33\xd2",
		"xxxxxx", 0,
		(uint32_t)patternAddrWings // I want the pattern that follows patternAddrWings - I don't want the first one met
	);
	if (jmpback == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("jmpback = %x", jmpback);

	Logger::Success("Successfully initialized");
	return true;
}

bool WingManager::unload() noexcept
{
    return false; // todo
}

void WingManager::tick() noexcept
{}
