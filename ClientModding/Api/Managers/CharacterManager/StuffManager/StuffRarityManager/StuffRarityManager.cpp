#include "StuffRarityManager.h"
#include "DefaultRarityTextStyle.h"
#include "DefaultRarityTextVnum.h"
#include "../../../../../MemoryHelper/PatternScan.h"
#include "../../../../../MemoryHelper/Patch.h"
#include "../../../../Properties/Logical/String.h"
#include "../../../GameFileManager/NScliManager/NScliManager.h"

namespace
{
	TextStyle defaultTextStyle(2, TextShadowOrientation::ShadowNone, Bgra(255, 255, 255, 255), Bgra(0, 0, 0, 0), TextAlignment::CenteredCentered);
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

			pop ebx;
			ret;
		}
	}

	uintptr_t jmpbackRarityResetTextStyleDisplay;
	int32_t aa = 5;

	void __declspec(naked) hk_rarityResetTextStyleDisplay() noexcept
	{
		__asm
		{
			push esi;
			mov esi, [defaultTextStyle];
			mov dword ptr[eax], esi;
			pop esi;
			jmp jmpbackRarityResetTextStyleDisplay;
		}
	}

	rarityToTextVnum rarityTextVnums;
	uintptr_t jmpbackRarityTextHover;
	char* lazyReturn{ nullptr }; // Ugly, but lazy to manually handle registers

	void __stdcall rarityTextDisplayHover(RarityType rarity)
	{
		if (rarityTextVnums.count(rarity) == 0)
		{
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

	uintptr_t jmpbackRarityTextSheetArmor;
	char* lazyReturnSheetArmor{ nullptr }; // Ugly, but lazy to manually handle registers

	void __stdcall rarityTextDisplaySheetArmor(RarityType rarity)
	{
		if (rarityTextVnums.count(rarity) == 0)
		{
			lazyReturnSheetArmor = nullptr;
			return;
		}

		// TODO: system to free str ?
		String* str = new String(NScliManager::GetConstString(rarityTextVnums[rarity]));
		lazyReturnSheetArmor = str->get();
	}

	void __declspec(naked) hk_rarityTextDisplaySheetArmor() noexcept
	{
		__asm
		{
			pushad;
			pushfd;

			push eax;

			call rarityTextDisplaySheetArmor;

			popfd;
			popad;

			push lazyReturnSheetArmor;

			jmp jmpbackRarityTextSheetArmor;
		}
	}

	uintptr_t jmpbackRarityTextSheetMainWeapon;
	char* lazyReturnSheetMainWeapon{ nullptr }; // Ugly, but lazy to manually handle registers

	void __stdcall rarityTextDisplaySheetMainWeapon(RarityType rarity)
	{
		if (rarityTextVnums.count(rarity) == 0)
		{
			lazyReturnSheetMainWeapon = nullptr;
			return;
		}

		// TODO: system to free str ?
		String* str = new String(NScliManager::GetConstString(rarityTextVnums[rarity]));
		lazyReturnSheetMainWeapon = str->get();
	}

	void __declspec(naked) hk_rarityTextDisplaySheetMainWeapon() noexcept
	{
		__asm
		{
			pushad;
			pushfd;

			push eax;

			call rarityTextDisplaySheetMainWeapon;

			popfd;
			popad;

			push lazyReturnSheetMainWeapon;

			jmp jmpbackRarityTextSheetMainWeapon;
		}
	}

	uintptr_t jmpbackRarityTextSheetSecondaryWeapon;
	char* lazyReturnSheetSecondaryWeapon{ nullptr }; // Ugly, but lazy to manually handle registers

	void __stdcall rarityTextDisplaySheetSecondaryWeapon(RarityType rarity)
	{
		if (rarityTextVnums.count(rarity) == 0)
		{
			lazyReturnSheetSecondaryWeapon = nullptr;
			return;
		}

		// TODO: system to free str ?
		String* str = new String(NScliManager::GetConstString(rarityTextVnums[rarity]));
		lazyReturnSheetSecondaryWeapon = str->get();
	}

	void __declspec(naked) hk_rarityTextDisplaySheetSecondaryWeapon() noexcept
	{
		__asm
		{
			pushad;
			pushfd;

			push eax;

			call rarityTextDisplaySheetSecondaryWeapon;

			popfd;
			popad;

			push lazyReturnSheetSecondaryWeapon;

			jmp jmpbackRarityTextSheetSecondaryWeapon;
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

	if (!initializeRarityTextDisplaySheet())
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
		Logger::Log("patternRarityTextStyle = %x", pattern);

		if (!Hook((BYTE*)pattern, (BYTE*)hk_rarityTextStyleDisplay, 6))
		{
			Logger::Error("Failed hooking");
			return false;
		}
	}
	{
		auto pattern = PatternScan(
			"\x33\xc9\x33\xd2\x8b\xc3\xe8\x00\x00\x00\x00\x8b\x00\x00\x00\x00\x00\xc7\x40\x02\xff\xff\xff\xff\x8b\x00\x00",
			"xxxxxxx????x?????xxxxxxxx??", 17
		);
		if (pattern == nullptr)
		{
			Logger::Error("Failed scanning pattern");
			return false;
		}
		Logger::Log("patternRarityResetTextStyle = %x", pattern);

		if (!Hook((BYTE*)pattern, (BYTE*)hk_rarityResetTextStyleDisplay, 6))
		{
			Logger::Error("Failed hooking");
			return false;
		}

		jmpbackRarityResetTextStyleDisplay = (uintptr_t)pattern + 7;
		Logger::Log("jmpbackRarityResetTextStyleDisplay = %x", jmpbackRarityResetTextStyleDisplay);
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
	Logger::Log("patternTextDisplayHover = %x", pattern);

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

	return true;
}

bool StuffRarityManager::initializeRarityTextDisplaySheet() noexcept
{
	{
		auto patternArmor = PatternScan(
			"\xba\x11\x00\x00\x00\x8b\xc6\x8b\x38\xff\x57\x0c\x8b\x00\x00\x00\x00\x00\x33\xd2\xe8\x00\x00\x00\x00\x8b\x15\x00\x00\x00\x00\xff\x74\x82\x08\x68\x00\x00\x00\x00\x8d\x00\x00\x00\x00\x00\xba\x12\x00\x00\x00\x8b\xc6",
			"xxxxxxxxxxxxx?????xxx????xx????xxxxx????x?????xxxxxxx", 25
		);
		if (patternArmor == nullptr)
		{
			Logger::Error("Failed scanning patternArmor");
			return false;
		}
		Logger::Log("patternArmor = %x", patternArmor);

		if (!Hook((BYTE*)patternArmor, (BYTE*)hk_rarityTextDisplaySheetArmor, 6))
		{
			Logger::Error("Failed hooking");
			return false;
		}

		jmpbackRarityTextSheetArmor = (uintptr_t)patternArmor + 10;
		Logger::Log("jmpbackRarityTextSheetArmor = %x", jmpbackRarityTextSheetArmor);
	}
	{
		auto patternMainWeapon = PatternScan(
			"\xba\x0b\x00\x00\x00\x8b\xc6\x8b\x38\xff\x00\x00\x8b\x00\x00\x00\x00\x00\x33\xd2\xe8\x00\x00\x00\x00\x8b\x15\x00\x00\x00\x00\xff\x74\x82\x08\x68\x00\x00\x00\x00\x8d\x00\x00\x00\x00\x00\xba\x0c\x00\x00\x00\x8b\xc6",
			"xxxxxxxxxx??x?????xxx????xx????xx??x????x?????xxxxxxx", 25
		);
		if (patternMainWeapon == nullptr)
		{
			Logger::Error("Failed scanning patternMainWeapon");
			return false;
		}
		Logger::Log("patternMainWeapon = %x", patternMainWeapon);

		if (!Hook((BYTE*)patternMainWeapon, (BYTE*)hk_rarityTextDisplaySheetMainWeapon, 6))
		{
			Logger::Error("Failed hooking");
			return false;
		}

		jmpbackRarityTextSheetMainWeapon = (uintptr_t)patternMainWeapon + 10;
		Logger::Log("jmpbackRarityTextSheetMainWeapon = %x", jmpbackRarityTextSheetMainWeapon);
	}
	{
		auto patternSecondaryWeapon = PatternScan(
			"\xba\x0e\x00\x00\x00\x8b\xc6\x8b\x38\xff\x00\x00\x8b\x00\x00\x00\x00\x00\x33\xd2\xe8\x00\x00\x00\x00\x8b\x15\x00\x00\x00\x00\xff\x74\x82\x08\x68\x00\x00\x00\x00\x8d\x00\x00\x00\x00\x00\xba\x0f\x00\x00\x00\x8b\xc6",
			"xxxxxxxxxx??x?????xxx????xx????xx??x????x?????xxxxxxx", 25
		);
		if (patternSecondaryWeapon == nullptr)
		{
			Logger::Error("Failed scanning patternSecondaryWeapon");
			return false;
		}
		Logger::Log("patternSecondaryWeapon = %x", patternSecondaryWeapon);

		if (!Hook((BYTE*)patternSecondaryWeapon, (BYTE*)hk_rarityTextDisplaySheetSecondaryWeapon, 6))
		{
			Logger::Error("Failed hooking");
			return false;
		}

		jmpbackRarityTextSheetSecondaryWeapon = (uintptr_t)patternSecondaryWeapon + 10;
		Logger::Log("jmpbackRarityTextSheetSecondaryWeapon = %x", jmpbackRarityTextSheetSecondaryWeapon);
	}

	return true;
}
