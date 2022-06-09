#pragma once
#include "../../Manager.h"
#include "IdleConfig.h"

class IdleManager : public Manager<IdleManagerConfig>
{
public:
	[[nodiscard]] explicit IdleManager(const IdleManagerConfig& Config) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	HWND hwnd{};
};

