#pragma once
#include "../../../Manager.h"
#include "NpcTalkRangeConfig.h"

class NpcTalkRangeManager : public Manager<NpcTalkRangeManagerConfig>
{
public:
	[[nodiscard]] explicit NpcTalkRangeManager(const NpcTalkRangeManagerConfig& Config) noexcept;

	void SetCurrentRange(int16_t Range) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;
};
