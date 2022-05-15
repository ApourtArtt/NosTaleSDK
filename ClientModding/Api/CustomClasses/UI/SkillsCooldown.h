#pragma once
#include "../../DelphiClasses/ClassSearcher.h"
#include "../Wrappers/Widgets/NewCharacterSkillInfoWidget.h"
#include "../Wrappers/Widgets/QuickSlotWidget.h"
#include "../../../MemoryHelper/TrampolineHook.h"

/**
 * @brief Class to manage the skills cooldown labels in-game.
 */
class SkillsCooldown
{
public:
	SkillsCooldown();
	~SkillsCooldown();

private:
	void getAddresses();
	void hookFunctions();

private:
	static constexpr int HOOK_NUMBER = 2;
	DWORD hookAddress[HOOK_NUMBER];
	TrampolineHook* trmpHook[HOOK_NUMBER];
};
