#pragma once
#include "../../../Manager.h"
#include "ArmorConfig.h"

class ArmorManager : public Manager<ArmorManagerConfig>
{
public:
	[[nodiscard]] explicit ArmorManager(const ArmorManagerConfig& Config) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;
};

