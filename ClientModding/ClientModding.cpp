#include "ClientModding.h"
#include "MemoryHelper/HwndGetter.h"
#include "Utils/Split.h"

ClientModding::ClientModding(const ClientModdingConfig& Config)
	: config(Config)
	, discordMng(Config.DiscordConfig)
	, wingsMng(Config.WingsConfig)
	, stuffMng(Config.StuffConfig)
	, uiMng(Config.UIConfig)
{
	packetMng.Subscribe(PacketType::RCVD, "tit", [this](std::string& Packet) { on_PR_tit(Packet); });

	packetMng.Subscribe(PacketType::RCVD, "st", [this](std::string& Packet) { on_PR_st(Packet); });
	packetMng.Subscribe(PacketType::RCVD, "aa_st", [this](std::string& Packet) { on_PR_aa_st(Packet); });

	packetMng.Subscribe(PacketType::RCVD, "pst", [this](std::string& Packet) { on_PR_pst(Packet); });
	packetMng.Subscribe(PacketType::RCVD, "aa_pst", [this](std::string& Packet) { on_PR_aa_pst(Packet); });
}

ClientModding::~ClientModding() {}

bool ClientModding::Initialize()
{
	auto _ = Logger::PushPopModuleName("ClientModding");

	hwnd = getHwnd();
	discordMng.Start();

	if (!ClassSearcher::Initialize())
		return false;

	ntWidgetHandler = TLBSWidgetHandler::getNosTaleUniqueInstance();
	if (ntWidgetHandler == nullptr)
		return false;

	ntSceneMng = TSceneManager::getNosTaleUniqueInstance();
	if (ntSceneMng == nullptr)
		return false;

	if (!packetMng.Initialize())
		return false;

	if (!wingsMng.Initialize())
		return false;

	if (!stuffMng.Initialize())
		return false;

	if (!uiMng.Initialize())
		return false;

	if (!connection.Initialize())
		return false;

	if (!mapCommon.Initialize())
		return false;

	Logger::Success("Successfully initialized");
	return true;
}

void ClientModding::Run()
{
	auto _ = Logger::PushPopModuleName("ClientModding");

	if (!beforeRun())
	{
		Logger::Error("Unable to run");
		return;
	}
	Logger::Log("Now running...");

	while (true)
	{
		Tick();
		Sleep(config.EventLoopDelay);
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

void ClientModding::on_PR_st(std::string& packet)
{
	PR_st p(packet);
	uiMng.GetSpyHpMpManager().On_PR_st(p);
}

void ClientModding::on_PR_aa_st(std::string& packet)
{
	PR_aa_st p(packet);
	uiMng.GetSpyHpMpManager().On_PR_aa_st(p);
}

void ClientModding::on_PR_pst(std::string& packet)
{
	PR_pst p(packet);
	uiMng.GetSpyHpMpManager().On_PR_pst(p);
}

void ClientModding::on_PR_aa_pst(std::string& packet)
{
	PR_aa_pst p(packet);
	uiMng.GetSpyHpMpManager().On_PR_aa_pst(p);
}
