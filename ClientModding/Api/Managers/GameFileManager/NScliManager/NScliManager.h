#pragma once
#include "../../Manager.h"
#include "NScliConfig.h"

class NScliManager : public Manager<NScliManagerConfig>
{
public:
	[[nodiscard]] explicit NScliManager(const NScliManagerConfig& Config) noexcept;

	[[nodiscard]] static const char* GetConstString(int32_t Vnum) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;
};
