#pragma once
#include "../Manager.h"
#include "GameFileConfig.h"
#include "NScliManager/NScliManager.h"

class GameFileManager : public Manager<GameFileManagerConfig>
{
public:
	[[nodiscard]] explicit GameFileManager(const GameFileManagerConfig& Config) noexcept;

	[[nodiscard]] NScliManager& GetNScliManager() noexcept { return nscliMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	NScliManager nscliMng;
};
