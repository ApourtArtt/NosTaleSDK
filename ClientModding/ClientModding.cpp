#include "ClientModding.h"
#include "MemoryHelper/HwndGetter.h"
#include "Utils/Split.h"

ClientModding::ClientModding()
{
	packetMng.Subscribe(PacketType::RCVD, "tit", [this](std::string& Packet) { on_PR_tit(Packet); });
}

ClientModding::~ClientModding() {}

bool ClientModding::Initialize()
{
	hwnd = getHwnd();

	if (int res = ClassSearcher::Initialize() != -1)
	{
		Logger::Log("[ClassSearcher] Failed initializing: %d", res);
		return false;
	}
	Logger::Log("[ClassSearcher] Successfully initialized");

	if (!discordMng.Start()) // If it fails, the player should still be able to play: don't return false
		Logger::Log("[DiscordManager] Failed starting");
	else
		Logger::Log("[DiscordManager] Successfully started");

	if (!packetMng.Initialize())
	{
		Logger::Log("[PacketManager] Failed initialization");
		return false;
	}
	Logger::Log("[PacketManager] Successfully initialized");

	if (!wingsMng.Initialize())
	{
		Logger::Log("[WingsManager] failed initialization");
		return false;
	}
	Logger::Log("[WingsManager] Successfully initialized");

	if (!connection.Initialize())
	{
		Logger::Log("[Connection] Failed initialization");
		return false;
	}
	Logger::Log("[Connection] Successfully initialized");

	if (!mapCommon.Initialize())
	{
		Logger::Log("[MapCommon] Failed initialization");
		return false;
	}
	Logger::Log("[MapCommon] Successfully initialized");

	ntWidgetHandler = TLBSWidgetHandler::getNosTaleUniqueInstance();
	if (ntWidgetHandler == nullptr)
	{
		Logger::Log("[TLBSWidgetHandler] Failed initialization");
		return false;
	}
	Logger::Log("[TLBSWidgetHandler] Successfully initialized: %x", ntWidgetHandler);

	ntSceneMng = TSceneManager::getNosTaleUniqueInstance();
	if (ntSceneMng == nullptr)
	{
		Logger::Log("[TSceneManager] Failed initialization");
		return false;
	}
	Logger::Log("[TSceneManager] Successfully initialized: %x", ntSceneMng);

	return true;
}

void ClientModding::Run(unsigned int sleepTime)
{
	if (!beforeRun())
	{
		Logger::Log("Unable to run");
		return;
	}
	Logger::Log("Now running...");

	while (true)
	{
		Sleep(sleepTime);
		Tick();
	}
}

void ClientModding::Tick()
{
	// Automatically turn off the game render when window is minimized
	if (!IsWindowVisible(hwnd))
		ntWidgetHandler->getGameRootWidget()->setVisible(false);
	else
		ntWidgetHandler->getGameRootWidget()->setVisible(true);
}

void ClientModding::on_PR_tit(std::string& packet)
{
	auto words = Split(packet, " ");
	std::string pseudo = words[2];
	discordMng.SetPseudonym(pseudo);
	discordMng.SetChannel(connection.servChan.GetChannel());
}
