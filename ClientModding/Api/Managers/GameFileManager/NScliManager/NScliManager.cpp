#include "NScliManager.h"
#include "../../../../MemoryHelper/PatternScan.h"
#include "../../../../MemoryHelper/Patch.h"
#include "../../../DelphiClasses/TNTConstStringList.h"
#include <map>

namespace
{
	uintptr_t jmpback;
	std::map<int32_t, const char*> nscliData;

	void __stdcall handleNSciDataNOS(TNTConstStringList* list)
	{
		auto _ = Logger::PushPopModuleName("NScliManager");
		for (auto i = 0; i < list->size(); i++)
		{
			auto elem = list->getItem(i);
			if (elem == nullptr)
			{
				Logger::Error("A string was nullptr");
				continue;
			}
			if (elem->getValue() == nullptr)
			{
				nscliData[elem->getVnum()] = "";
				continue;
			}
			auto size = strlen(elem->getValue());
			char* elemCopy = (char*)malloc(size + 1);
			if (!elemCopy)
			{
				Logger::Error("malloc failed");
				continue;
			}
			memcpy(elemCopy, elem->getValue(), size);
			elemCopy[size] = 0;
			nscliData.emplace(elem->getVnum(), elemCopy);
		}
	}

	void __declspec(naked) hk_handleNSciDataNOS() noexcept
	{
		__asm
		{
			push ebx;
			push esi;
			push edi;
			mov ebx, eax;

			pushad;
			pushfd;

			push eax;

			call handleNSciDataNOS;

			popfd;
			popad;

			jmp jmpback;
		}
	}
}

NScliManager::NScliManager(const NScliManagerConfig& Config) noexcept
	: Manager(Config, "NScliManager")
{}

const char* NScliManager::GetConstString(int32_t Vnum) noexcept
{
	if (nscliData.count(Vnum) == 0)
		return "";
	return nscliData[Vnum];
}

bool NScliManager::initialize() noexcept
{
	auto pattern = PatternScan(
		"\x75\x00\x53\x56\x57\x8b\xd8\x8d\x00\x00\x33\xc0\x55",
		"x?xxxxxx??xxx", 2
	);
	if (pattern == nullptr)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("pattern = %x", pattern);

	if (!Hook((BYTE*)pattern, (BYTE*)hk_handleNSciDataNOS, 5))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	jmpback = (uintptr_t)pattern + 5;
	Logger::Log("jmpback = %x", jmpback);

	Logger::Success("Successfully initialized");
	return true;
}

bool NScliManager::unload() noexcept
{
	return false; // todo
}

void NScliManager::tick() noexcept
{}
