#pragma once
#include "../Manager.h"
#include "CharacterConfig.h"
#include "StuffManager/StuffManager.h"

class CharacterManager : public Manager<CharacterManagerConfig>
{
public:
	[[nodiscard]] explicit CharacterManager(const CharacterManagerConfig& Config) noexcept;

	[[nodiscard]] StuffManager& GetStuffManager() noexcept { return stuffMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	StuffManager stuffMng;
};
