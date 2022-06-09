#pragma once
#include "../Manager.h"
#include "CharacterConfig.h"
#include "StuffManager/StuffManager.h"
#include "InteractionManager/InteractionManager.h"

class CharacterManager : public Manager<CharacterManagerConfig>
{
public:
	[[nodiscard]] explicit CharacterManager(const CharacterManagerConfig& Config) noexcept;

	[[nodiscard]] StuffManager& GetStuffManager() noexcept { return stuffMng; }
	[[nodiscard]] InteractionManager& GetInteractionManager() noexcept { return interactionMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	StuffManager stuffMng;
	InteractionManager interactionMng;
};
