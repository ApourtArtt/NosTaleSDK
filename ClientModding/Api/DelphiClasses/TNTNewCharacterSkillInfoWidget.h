#pragma once
#include "TEWCustomFormWidget.h"
#include "TNTTimeAniIcon.h"
#include "TNTItemList.h"
#include "../../MemoryHelper/Patch.h"
#include "../../MemoryHelper/PatternScan.h"
#pragma pack(push, 1)

// TODO: Deep reverse

namespace TNTNewCharacterSkillInfoWidgetInternal
{
	static uintptr_t jmpback;
	static std::map<int32_t, std::function<void()>> skillFuncs;

	static void __stdcall callSkill(void* skillStruct)
	{
		int32_t id = *(int32_t*)skillStruct;
		if (skillFuncs.count(id) == 0)
			return;
		skillFuncs[id]();
	}

	static void __declspec(naked) hk_addMotionSkillEvent() noexcept
	{
		__asm
		{
			push ebp;
			mov ebp, esp;
			push ecx;
			mov ecx, 0x9;

			pushad;
			pushfd;

			push ebx;

			call callSkill;

			popfd;
			popad;

			jmp jmpback;
		}
	}
};

class TNTNewCharacterSkillInfoWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTNewCharacterSkillInfoWidget";

	TNTItemList* getMotionList() noexcept { return motionList; }

	[[nodiscard]] static bool addMotionSkillEvent(int32_t SkillId, std::function<void()> Func)
	{
		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			auto _ = Logger::PushPopModuleName(NAME.data());

			patternAddr = PatternScan(
				"\x55\x8b\xec\x51\xb9\x09\x00\x00\x00\x6a\x00\x6a\x00\x49\x75\xf9\x51\x87\x4d\xfc\x53\x56\x8b\xda",
				"xxxxxxxxxxxxxxxxxxxxxxxx", 0
			);
			if (patternAddr == nullptr)
			{
				Logger::Error("Fail scanning pattern");
				return false;
			}
			Logger::Log("patternAddr = %x", patternAddr);

			if (!Hook((BYTE*)patternAddr, (BYTE*)TNTNewCharacterSkillInfoWidgetInternal::hk_addMotionSkillEvent, 9))
			{
				Logger::Error("Fail creating hook");
				return false;
			}
			TNTNewCharacterSkillInfoWidgetInternal::jmpback = ((uintptr_t)patternAddr + 9);

			Logger::Success("Successfully initialized");
		}

		TNTNewCharacterSkillInfoWidgetInternal::skillFuncs.emplace(SkillId, Func);

		return true;
	}

	char pad_00BC[52]; //0x00BC
	TNTTimeAniIcon* aSlotsAniIcons[24]; //0x00F0
	char pad_0150[0x10]; //0x0150
	TNTItemList* motionList; // 0x0160
	char pad[128]; // 0x164
};
static_assert(sizeof(TNTNewCharacterSkillInfoWidget) == 0x1E4, "TNTNewCharacterSkillInfoWidget does not have a size of 0x1E4");

#pragma pack(pop)
