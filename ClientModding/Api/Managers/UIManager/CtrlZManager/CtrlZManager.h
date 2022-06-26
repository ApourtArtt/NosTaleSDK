#pragma once
#include "../../Manager.h"
#include "CtrlZConfig.h"

class CtrlZManager : public Manager<CtrlZManagerConfig>
{
public:
	[[nodiscard]] explicit CtrlZManager(const CtrlZManagerConfig& Config) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;
};

