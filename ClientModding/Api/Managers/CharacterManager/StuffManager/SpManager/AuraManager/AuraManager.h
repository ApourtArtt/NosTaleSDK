#pragma once
#include "../../../../Manager.h"
#include "AuraConfig.h"

class AuraManager : public Manager<AuraManagerConfig>
{
public:
	[[nodiscard]] explicit AuraManager(const AuraManagerConfig& Config) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;
};

