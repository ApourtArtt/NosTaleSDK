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
			push esi;

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
		"\x55\x8b\xec\x51\x53\x56\x84\xd2\x74\x08\x83\xc4\xf0\xe8\x00\x00\x00\x00\x8b\xda\x8b\xf0\x8b\x45\x0c\x83\xf8\x15",
		"xxxxxxxxxxxxxx????xxxxxxxxxx", 25
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

	jmpback = (uintptr_t)PatternScan("\x6a\xff\x33\xc9\x33\xd2\x8b\xc6",
		"xxxxxxxx", 0,
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
