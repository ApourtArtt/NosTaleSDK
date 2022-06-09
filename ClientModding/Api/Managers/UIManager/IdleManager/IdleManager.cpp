#include "IdleManager.h"
#include "../../../../MemoryHelper/HwndGetter.h"
#include "../../../DelphiClasses/TLBSWidgetHandler.h"

IdleManager::IdleManager(const IdleManagerConfig& Config) noexcept
	: Manager(Config, "IdleManager")
{}

bool IdleManager::initialize() noexcept
{
	if (!config.Activated)
	{
		Logger::Log("Not activated");
		return true;
	}

	hwnd = getHwnd();
	if (hwnd == NULL)
	{
		Logger::Error("Failed retrieving HWND");
		return false;
	}

	Logger::Success("Successfully initialized");
	return true;
}

bool IdleManager::unload() noexcept
{
	return true;
}

void IdleManager::tick() noexcept
{
	if (!config.Activated)
		return;

	TLBSWidgetHandler::getNosTaleUniqueInstance()->getGameRootWidget()->setVisible(IsWindowVisible(hwnd));
}
