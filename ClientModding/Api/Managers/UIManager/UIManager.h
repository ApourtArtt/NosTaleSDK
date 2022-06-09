#pragma once
#include "../Manager.h"
#include "UIConfig.h"
#include "SpyHpMpManager/SpyHpMpManager.h"
#include "IdleManager/IdleManager.h"

class UIManager : public Manager<UIManagerConfig>
{
public:
	[[nodiscard]] explicit UIManager(const UIManagerConfig& Config) noexcept;

	[[nodiscard]] SpyHpMpManager& GetSpyHpMpManager() noexcept { return spyHpMpMng; }
	[[nodiscard]] IdleManager& GetIdleManager() noexcept { return idleMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	SpyHpMpManager spyHpMpMng;
	IdleManager idleMng;
};
