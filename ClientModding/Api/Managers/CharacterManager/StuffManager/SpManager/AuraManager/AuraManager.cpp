#include "AuraManager.h"
#include "DefaultAura.h"
#include "../../../../../../MemoryHelper/Patch.h"
#include "../../../../../../MemoryHelper/PatternScan.h"
#include "../../../../../DelphiClasses/TNTSpecialDragonFx.h"

namespace
{
	uintptr_t jmpback;
	levelToId auras;

	void __stdcall aurasDisplay(TNTSpecialDragonFx* aura, auraLevel level)
	{
		//Logger::Log("aura: %x level:%d", aura, level);
		if (auras.count(level) == 0)
		{
			aura->setWeirdCounter(-1);
			return;
		}

		aura->setAuraStyle(auras[level]);
		return;
	}

	void __declspec(naked) hk_aurasDisplay() noexcept
	{
		__asm
		{
			pushad;
			pushfd;

			push ecx;
			push esi;

			call aurasDisplay;

			popfd;
			popad;

			jmp jmpback;
		}
	}
}

AuraManager::AuraManager(const AuraManagerConfig& Config) noexcept
	: Manager(Config, "AuraManager")
{
	// First additionalAuras then defaultAuras
	auras = config.AdditionalAuras;
	auras.merge(defaultAuras);
}

bool AuraManager::initialize() noexcept
{
	auto patternAddrAura = PatternScan(
		"\x55\x8b\xec\x51\x53\x56\x84\xd2\x74\x00\x83\xc4\x00\xe8\x00\x00\x00\x00\x8b\xda\x8b\xf0\x8a\x40\x00\x88\x40\x00\x83\xc1\xf0\x83\xf9\x04\x77\x00",
		"xxxxxxxxx?xx?x????xxxxx??x??xxxxxxx?", 28
	);
	if (patternAddrAura == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("patternAddrAura = %x", patternAddrAura);

	if (!Hook((BYTE*)patternAddrAura, (BYTE*)hk_aurasDisplay, 9))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	jmpback = (uintptr_t)PatternScan("\x6a\xff\x33\xc9\x33\xd2\x8b\xc6\xe8\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x89\x45\xfc\x8d\x45\xfc\x50\x6a\x00\x8b\x46\x10\x33\xc9\x8b\x55\x0c",
		"xxxxxxxxx????x????xxxxxxxxxxxxxxxxx", 0,
		(uint32_t)patternAddrAura // I want the pattern that follows patternAddrAura - I don't want the first one met
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

bool AuraManager::unload() noexcept
{
	return false; // todo
}

void AuraManager::tick() noexcept
{}
