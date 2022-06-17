#include "StuffRarityManager.h"
#include "DefaultRarityTextStyle.h"
#include "DefaultRarityTextVnum.h"
#include "../../../../../MemoryHelper/PatternScan.h"
#include "../../../../../MemoryHelper/Patch.h"
#include "../../../../Properties/Logical/String.h"
#include "../../../GameFileManager/NScliManager/NScliManager.h"

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

	rarityToTextVnum rarityTextVnums;
	uintptr_t jmpbackRarityTextHover;
	char* lazyReturn{ nullptr }; // Ugly, but lazy to manually handle registers

	void __stdcall rarityTextDisplayHover(RarityType rarity)
	{
		if (rarityTextVnums.count(rarity) == 0)
		{
			Logger::Error("fail avec %d", rarity);
			lazyReturn = nullptr;
			return;
		}

		// TODO: system to free str ?
		String* str = new String(NScliManager::GetConstString(rarityTextVnums[rarity]));
		lazyReturn = str->get();
	}

	void __declspec(naked) hk_rarityTextDisplayHover() noexcept
	{
		__asm
		{
			pushad;
			pushfd;

			push ebx;

			call rarityTextDisplayHover;

			popfd;
			popad;

			push lazyReturn;

			jmp jmpbackRarityTextHover;
		}
	}
}

StuffRarityManager::StuffRarityManager(const StuffRarityManagerConfig& Config) noexcept
    : Manager(Config, "StuffRarityManager")
{
	rarityTextStyles = config.AdditionalRarityTextStyle;
	rarityTextStyles.merge(defaultRarityTextStyle);
	
	rarityTextVnums = Config.AdditionalRarityTextVnum;
	rarityTextVnums.merge(defaultRarityTextVnum);


}

bool StuffRarityManager::initialize() noexcept
{
	if (!initializeRarityTextStyleDisplay())
		return false;

	if (!initializeRarityTextDisplayHover())
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
	auto pattern = PatternScan(
		"\x0f\xbf\xc0\x83\xc0\x02\x83\xf8\x0a",
		"xxxxxxxxx", 3
	);
	if (pattern == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("pattern = %x", pattern);

	if (!Hook((BYTE*)pattern, (BYTE*)hk_rarityTextStyleDisplay, 6))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	return true;
}

bool StuffRarityManager::initializeRarityTextDisplayHover() noexcept
{
	auto pattern = PatternScan(
		"\x0f\xbf\xc3\x8b\x15\x00\x00\x00\x00\xff\x74\x82\x08\xff\x75\xfc\x56",
		"xxxxx????xxxxxxxx", 3
	);
	if (pattern == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("pattern = %x", pattern);

	if (!Hook((BYTE*)pattern, (BYTE*)hk_rarityTextDisplayHover, 6))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	jmpbackRarityTextHover = (uintptr_t)pattern + 10;
	Logger::Log("jmpbackRarityTextHover = %x", jmpbackRarityTextHover);

	// Also need to NOP the "if (rarity < -2 || rarity > 8)" condition and its body
	auto patternIf = PatternScan(
		"\x64\xff\x30\x64\x89\x20\x66\x83\xfb\xfe\x7c\x00\x66\x83\xfb\x08\x7e\x00",
		"xxxxxxxxxxx?xxxxx?", 6
	);
	if (patternIf == nullptr)
	{
		Logger::Error("Failed scanning patternIf");
		return false;
	}
	Logger::Log("patternIf = %x", patternIf);

	if (!Nop((BYTE*)patternIf, (uintptr_t)pattern - (uintptr_t)patternIf))
	{
		Logger::Error("Failed nopping");
		return false;
	}

	for (auto const& [key, val] : rarityTextVnums)
	{
		Logger::Log("------: %d : %d : %s", (int)key, val, NScliManager::GetConstString(val));
	}

	return true;
}
