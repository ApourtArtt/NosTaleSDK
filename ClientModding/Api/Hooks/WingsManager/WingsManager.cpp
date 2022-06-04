#include "WingsManager.h"
#include "DefaultWings.h"
#include "DefaultAuras.h"
#include "../../../Utils/Logger.h"
#include "../../../MemoryHelper/PatternScan.h"
#include "../../../MemoryHelper/Patch.h"

namespace
{
	uintptr_t jmpbackWings, jmpbackAura;

	wingStyleId style;
	wingLevel level;
	std::map<wingStyleId, levelToId> wings = defaultWings;

	levelToId auras;
}

void __declspec(naked) auraHook() noexcept
{
	// Is issue v is done my official client but not by the hook
	//add ecx, -0x10;
	__asm
	{
		pushad;
		pushfd;

		mov level, ecx;
	}

	auraId id;

	if (auras.count(level) == 0)
	{
		__asm
		{
			mov dword ptr[esi + 0xC], 0xffffffff
		}
		goto back; // RETURN
	}

	id = auras[level];

	__asm
	{
		mov ecx, id
		mov dword ptr[esi + 0x10], eax
		mov ecx, level
	}

back: // RETURN
	__asm
	{
		popfd;
		popad;

		jmp jmpbackAura;
	}
}

void __declspec(naked) wingsHook() noexcept
{
	__asm
	{
		pushad;
		pushfd;

		mov style, eax;
		mov level, ecx;
	}

	wingId id;

	if (level == ARENA_WINNER_SKELETON_LEVEL)
	{
		__asm
		{
			mov eax, ARENA_WINNER_SKELETON_ID
			mov dword ptr[esi + 0x10], eax
			mov eax, style
		}
		goto back; // RETURN
	}
	else if (level == ARENA_WINNER_WINGS_LEVEL)
	{
		__asm
		{
			mov eax, ARENA_WINNER_WINGS_ID
			mov dword ptr[esi + 0x10], eax
			mov eax, style
		}
		goto back; // RETURN
	}

	if (wings.count(style) == 0)
	{
		__asm
		{
			mov dword ptr[esi + 0xC], 0xffffffff
		}
		goto back; // RETURN
	}

	if (wings[style].count(level) == 0)
	{
		__asm
		{
			mov dword ptr[esi + 0xC], 0xffffffff
		}
		goto back; // RETURN
	}

	id = wings[style][level];

	__asm
	{
		mov eax, id
		mov dword ptr[esi + 0x10], eax
		mov eax, style
	}

	back: // RETURN
	__asm
	{
		popfd;
		popad;
		jmp jmpbackWings;
	}
}

WingsManager::WingsManager(const WingsManagerConfig& Config)
	: config(Config)
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

	// First additionalAuras then defaultAuras
	auras = config.AdditionalAuras;
	auras.merge(defaultAuras);
}

bool WingsManager::Initialize()
{
	auto _ = Logger::PushPopModuleName("WingsManager");

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

	if (!Hook((BYTE*)patternAddrWings, (BYTE*)wingsHook, 9))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	jmpbackWings = (uintptr_t)PatternScan("\x6a\xff\x33\xc9\x33\xd2\x8b\xc6",
		"xxxxxxxx", 0,
		(uint32_t)patternAddrWings // I want the pattern that follows patternAddrWings - I don't want the first one met
	);
	if (jmpbackWings == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("jmpbackWings = %x", jmpbackWings);

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

	if (!Hook((BYTE*)patternAddrAura, (BYTE*)auraHook, 9))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	jmpbackAura = (uintptr_t)PatternScan("\x6a\xff\x33\xc9\x33\xd2\x8b\xc6\xe8\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x89\x45\xfc\x8d\x45\xfc\x50\x6a\x00\x8b\x46\x10\x33\xc9\x8b\x55\x0c",
		"xxxxxxxxx????x????xxxxxxxxxxxxxxxxx",0,
		(uint32_t)patternAddrAura // I want the pattern that follows patternAddrAura - I don't want the first one met
	);
	if (jmpbackAura == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("jmpbackAura = %x", jmpbackAura);

	Logger::Success("Successfully initialized");
    return true;
}
