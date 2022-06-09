#pragma once
#include "../../Manager.h"
#include "InteractionConfig.h"
#include "NpcTalkRangeNpcManager/NpcTalkRangeManager.h"

class InteractionManager : public Manager<InteractionManagerConfig>
{
public:
	[[nodiscard]] explicit InteractionManager(const InteractionManagerConfig& Config) noexcept;

	[[nodiscard]] NpcTalkRangeManager& GetNpcTalkRangeManager() noexcept { return npcTalkRangeMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	NpcTalkRangeManager npcTalkRangeMng;
};
