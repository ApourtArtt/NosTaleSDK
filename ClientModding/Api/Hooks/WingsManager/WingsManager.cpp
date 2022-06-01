#include "WingsManager.h"
#include "DefaultWings.h"
#include "../../../Utils/Logger.h"
#include "../../../MemoryHelper/PatternScan.h"
#include "../../../MemoryHelper/Patch.h"

namespace
{
	uintptr_t jmpback;

	wingStyleId style;
	wingLevel level;
	
	std::map<wingStyleId, levelToId> wings = defaultWings;
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

	//style &= 0xFF;
	//level &= 0xFF;

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
			mov dword ptr[esi + 0x10], 0x4b4
		}
		goto back; // RETURN
	}

	if (wings[style].count(level) == 0)
	{
		__asm
		{
			mov dword ptr[esi + 0x10], 0x4b5
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
		jmp jmpback;
	}
}

WingsManager::WingsManager(const WingsManagerConfig& Config)
	: config(Config)
{
	wings.merge(config.AdditionalWings);
}

bool WingsManager::Initialize()
{
	auto patternAddr = PatternScan(
		"\x55\x8b\xec\x51\x53\x56\x84\xd2\x74\x08\x83\xc4\xf0\xe8\x00\x00\x00\x00\x8b\xda\x8b\xf0\x8b\x45\x0c\x83\xf8\x15",
		"xxxxxxxxxxxxxx????xxxxxxxxxx",
		25
	);

	Logger::Log("[WingsManager] Pattern address: %x", patternAddr);

	Hook((BYTE*)patternAddr, (BYTE*)wingsHook, 9);

	jmpback = (uintptr_t)PatternScan("\x6a\xff\x33\xc9\x33\xd2\x8b\xc6",
		"xxxxxxxx",
		0,
		(uint32_t)patternAddr // I want the pattern that follows patternAddr - I don't want the first one met
	);

	Logger::Log("[WingsManager] Pattern address JumpBack: %x", jmpback);

    return true;
}
