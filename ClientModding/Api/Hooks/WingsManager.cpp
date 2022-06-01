#include "WingsManager.h"
#include "../../Utils/Logger.h"
#include "../../MemoryHelper/PatternScan.h"
#include "../../MemoryHelper/Patch.h"
#include <map>

namespace
{
	typedef int32_t wingStyleId;
	typedef int32_t wingLevel;
	typedef int32_t wingId;
	typedef std::map<wingLevel, wingId> levelToId;

	uintptr_t jmpback;

	wingStyleId style;
	wingLevel level;

	constexpr wingLevel ARENA_WINNER_SKELETON_LEVEL = 96;
	constexpr wingLevel ARENA_WINNER_WINGS_LEVEL = 97;

	constexpr wingId ARENA_WINNER_SKELETON_ID = 0xF77;
	constexpr wingId ARENA_WINNER_WINGS_ID = 0xF78;

	constexpr wingStyleId NO_SKIN = 0;
	constexpr wingStyleId DEVIL_WING = 2;

	std::map<wingStyleId, levelToId> wings =
	{
		{ NO_SKIN, levelToId
			{
				{ 1, 1200 },
				{ 2, 1200 },
				{ 3, 1201 },
				{ 4, 1201 },
				{ 5, 1202 },
				{ 6, 1202 },
				{ 7, 1203 },
				{ 8, 1203 },
				{ 9, 1204 },
				{ 10, 1204 },
				{ 11, 1205 },
				{ 12, 1206 },
				{ 13, 1207 },
				{ 14, 1208 },
				{ 15, 1209 },
				{ 16, 3959 },
				{ 17, 3959 },
				{ 18, 3959 },
				{ 19, 3959 },
				{ 20, 3959 },
			}
		},
		{ DEVIL_WING, levelToId
			{
				{ 1, 1220 },
				{ 2, 1220 },
				{ 3, 1221 },
				{ 4, 1221 },
				{ 5, 1222 },
				{ 6, 1222 },
				{ 7, 1223 },
				{ 8, 1223 },
				{ 9, 1224 },
				{ 10, 1224 },
				{ 11, 1225 },
				{ 12, 1226 },
				{ 13, 1227 },
				{ 14, 1228 },
				{ 15, 1229 },
				{ 16, 1229 },
				{ 17, 1229 },
				{ 18, 1229 },
				{ 19, 1229 },
				{ 20, 1229 },
			}
		},
	};
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
		(uint32_t)patternAddr
	);

	Logger::Log("[WingsManager] Pattern address JumpBack: %x", jmpback);

    return true;
}
