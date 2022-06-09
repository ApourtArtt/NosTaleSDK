#pragma once
#include "../Manager.h"
#include "ConnectionConfig.h"
#include "ServChanManager/ServChanManager.h"

class ConnectionManager : public Manager<ConnectionManagerConfig>
{
public:
	[[nodiscard]] explicit ConnectionManager(const ConnectionManagerConfig& Config) noexcept;

	[[nodiscard]] ServChanManager& GetServChanManager() noexcept { return servChanMng; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

private:
	ServChanManager servChanMng;
};
