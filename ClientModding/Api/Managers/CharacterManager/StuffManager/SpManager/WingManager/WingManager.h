#pragma once
#include "../../../../Manager.h"
#include "WingConfig.h"

class WingManager : public Manager<WingManagerConfig>
{
public:
	[[nodiscard]] explicit WingManager(const WingManagerConfig& Config) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;
};
