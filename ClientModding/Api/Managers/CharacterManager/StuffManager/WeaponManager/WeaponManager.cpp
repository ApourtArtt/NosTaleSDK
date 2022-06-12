#include "WeaponManager.h"
#include "DefaultWeaponGlow.h"
#include "../../../../DelphiClasses/TMapPlayerObj.h"
#include "../../../../../MemoryHelper/Patch.h"
#include "../../../../../MemoryHelper/PatternScan.h"

namespace
{
	uintptr_t jmpbackUpgradeRarityDisplay;
	std::map<RarityType, std::map<Upgrade, WeaponGlow>> weaponGlows = defaultWeaponGlows;

	void __stdcall upgradeRarityDisplay(TMapPlayerObj* player, RarityType weaponRarity, Upgrade weaponUpgrade)
	{
		player->setWeaponRarity(weaponRarity);
		player->setWeaponUpgrade(weaponUpgrade);

		WeaponGlow glow;
		glow = defaultNoGlow;

		if (weaponGlows.count(weaponRarity) > 0 && weaponGlows[weaponRarity].count(weaponUpgrade) > 0)
			glow = weaponGlows[weaponRarity][weaponUpgrade];

		player->setWeaponGlow(glow);
	}

	void __declspec(naked) hk_upgradeRarityDisplay() noexcept
	{
		__asm
		{
			pushad;
			pushfd;

			push cl;
			push dl;
			push eax;

			call upgradeRarityDisplay;

			popfd;
			popad;

			jmp jmpbackUpgradeRarityDisplay;
		}
	}
}

WeaponManager::WeaponManager(const WeaponManagerConfig& Config) noexcept
	: Manager(Config, "WeaponManager")
{
	for (auto const& [k1, v1] : config.AdditionalWeaponsGlow)
	{
		if (weaponGlows.find(k1) == weaponGlows.end())
			weaponGlows.insert({ k1, v1 });
		else
		{
			for (auto const& [k2, v2] : v1)
			{
				if (weaponGlows[k1].find(k2) == weaponGlows[k1].end())
					weaponGlows[k1].insert({ k2, v2 });
				else
					weaponGlows[k1][k2] = v2;
			}
		}
	}
}

bool WeaponManager::initialize() noexcept
{
	auto patternAddrUpgradeRarityDisplay = PatternScan(
		"\x53\x85\xc0\x0f\x84\xee\x04\x00\x00\x80\xb8\x06\x02\x00\x00\x00\x0f\x87\xe1\x04\x00\x00\x80\xfa\x09\x73\x00",
		"xxxxx????x??????xx????xx?x?", 22
	);
	if (patternAddrUpgradeRarityDisplay == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("patternAddrUpgradeRarityDisplay = %x", patternAddrUpgradeRarityDisplay);

	if (!Hook((BYTE*)patternAddrUpgradeRarityDisplay, (BYTE*)hk_upgradeRarityDisplay, 6))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	jmpbackUpgradeRarityDisplay = (uintptr_t)PatternScan("\x5B\xC3",
		"xx", 0,
		(uint32_t)patternAddrUpgradeRarityDisplay // I want the pattern that follows patternAddrWings - I don't want the first one met
	);
	if (jmpbackUpgradeRarityDisplay == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("jmpbackUpgradeRarityDisplay = %x", jmpbackUpgradeRarityDisplay);

	Logger::Success("Successfully initialized");
	return true;
}

bool WeaponManager::unload() noexcept
{
    return false; // todo
}

void WeaponManager::tick() noexcept
{}
