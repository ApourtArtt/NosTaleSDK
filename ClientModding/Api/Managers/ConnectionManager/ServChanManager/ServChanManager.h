#pragma once
#include "../../Manager.h"
#include "ServChanConfig.h"

class ServChanManager : public Manager<ServChanManagerConfig>
{
public:
	[[nodiscard]] explicit ServChanManager(const ServChanManagerConfig& Config) noexcept;

	[[nodiscard]] short GetServer() noexcept;
	[[nodiscard]] short GetChannel() noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	uintptr_t address{ NULL };
};