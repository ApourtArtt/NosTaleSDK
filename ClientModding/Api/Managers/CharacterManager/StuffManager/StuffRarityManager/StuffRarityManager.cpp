#include "StuffRarityManager.h"
#include "DefaultWeaponRarityTextStyle.h"
#include "../../../../../MemoryHelper/PatternScan.h"
#include "../../../../../MemoryHelper/Patch.h"

namespace
{
	rarityToTextStyle rarityTextStyles;

	void __stdcall rarityTextStyleDisplay(TextStyle* textStyle, RarityType rarity)
	{
		if (rarityTextStyles.count(rarity) == 0)
			return;

		*textStyle = rarityTextStyles[rarity];
	}

	void __declspec(naked) hk_rarityTextStyleDisplay() noexcept
	{
		__asm
		{
			pushad;
			pushfd;

			push eax;
			push ebx;

			call rarityTextStyleDisplay;

			popfd;
			popad;

			// Possible with a pattern but would require the NOP following the return
			// I prefer to do it manually in order to avoid such a fragile pattern
			pop ebx;
			ret;
		}
	}
}

StuffRarityManager::StuffRarityManager(const StuffRarityManagerConfig& Config) noexcept
    : Manager(Config, "StuffRarityManager")
{
	rarityTextStyles = config.AdditionalWeaponsRarityTextStyle;
	rarityTextStyles.merge(defaultRarityTextStyle);
}

bool StuffRarityManager::initialize() noexcept
{
	if (!initializeRarityTextStyleDisplay())
		return false;

	Logger::Success("Successfully initialized");
    return true;
}

bool StuffRarityManager::unload() noexcept
{
    return false; // todo
}

void StuffRarityManager::tick() noexcept
{}

bool StuffRarityManager::initializeRarityTextStyleDisplay() noexcept
{
	auto patternAddrRarityTextStyleDisplay = PatternScan(
		"\x0f\xbf\xc0\x83\xc0\x02\x83\xf8\x0a",
		"xxxxxxxxx", 3
	);
	if (patternAddrRarityTextStyleDisplay == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("patternAddrRarityTextStyleDisplay = %x", patternAddrRarityTextStyleDisplay);

	if (!Hook((BYTE*)patternAddrRarityTextStyleDisplay, (BYTE*)hk_rarityTextStyleDisplay, 6))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	return true;
}
