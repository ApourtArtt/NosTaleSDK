#include "ArmorManager.h"
#include "DefaultArmorEffect.h"
#include "../../../../DelphiClasses/TMapPlayerObj.h"
#include "../../../../../MemoryHelper/Patch.h"
#include "../../../../../MemoryHelper/PatternScan.h"

namespace
{
	uintptr_t jmpbackUpgradeRarityDisplay;
	effectsMap armorEffects = defaultArmorEffects;
	EffectId lazyReturn; // Ugly.

	void __stdcall upgradeRarityDisplay(RarityType armorRarity, Upgrade armorUpgrade)
	{
		if (armorEffects.count(armorRarity) > 0 && armorEffects[armorRarity].count(armorUpgrade) > 0)
			lazyReturn = armorEffects[armorRarity][armorUpgrade];
		else
			lazyReturn = defaultNoEffect;
	}

	void __declspec(naked) hk_upgradeRarityDisplay() noexcept
	{
		__asm
		{
			pushad;
			pushfd;

			push edi;
			push esi;

			call upgradeRarityDisplay;

			popfd;
			popad;

			mov eax, lazyReturn;

			jmp jmpbackUpgradeRarityDisplay;
		}
	}
}

ArmorManager::ArmorManager(const ArmorManagerConfig& Config) noexcept
	: Manager(Config, "ArmorManager")
{
	for (auto const& [k1, v1] : config.AdditionalEffects)
	{
		if (armorEffects.find(k1) == armorEffects.end())
			armorEffects.insert({ k1, v1 });
		else
		{
			for (auto const& [k2, v2] : v1)
			{
				if (armorEffects[k1].find(k2) == armorEffects[k1].end())
					armorEffects[k1].insert({ k2, v2 });
				else
					armorEffects[k1][k2] = v2;
			}
		}
	}
}

bool ArmorManager::initialize() noexcept
{
	auto patternStartOfNop = PatternScan(
		"\x84\xc0\x0f\x84\x00\x00\x00\x00\xf6\x00\x00\x00\x00\x00\x02\x0f\x85\x00\x00\x00\x00\x4e\x83\xee\x06\x72\x00\x83\xee\x02\x0f\x82\x00\x00\x00\x00\xe9\x00\x00\x00\x00",
		"xxxx????x??????xx????xxxxx?xxxxx????x????", 21
	);
	if (patternStartOfNop == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("patternStartOfNop = %x", patternStartOfNop);

	auto patternEndOfNop = PatternScan(
		"\xe8\x00\x00\x00\x00\x89\x04\x24\x54\x6a\x00\x33\xc9\x8b\xd3\xb8\x00\x00\x00\x00",
		"x????xxxxxxxxxxx????", 0
	);
	if (patternEndOfNop == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("patternEndOfNop = %x", patternEndOfNop);

	if (!Nop((BYTE*)patternStartOfNop, (uintptr_t)patternEndOfNop - (uintptr_t)patternStartOfNop))
	{
		Logger::Error("Failed noping");
		return false;
	}

	if (!Hook((BYTE*)((uintptr_t)patternEndOfNop + 15), (BYTE*)hk_upgradeRarityDisplay, 5))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	jmpbackUpgradeRarityDisplay = ((uintptr_t)patternEndOfNop + 20);
	Logger::Log("jmpbackUpgradeRarityDisplay = %x", jmpbackUpgradeRarityDisplay);

	Logger::Success("Successfully initialized");
	return true;
}

bool ArmorManager::unload() noexcept
{
	return false; // todo
}

void ArmorManager::tick() noexcept
{}
