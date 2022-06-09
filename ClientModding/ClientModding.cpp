#include "ClientModding.h"
#include "MemoryHelper/HwndGetter.h"
#include "Utils/Split.h"
#include "Api/DelphiClasses/TLBSWidgetHandler.h"
#include "Api/DelphiClasses/TSceneManager.h"


ClientModding::ClientModding(const ClientModdingConfig& Config)
	: config(Config)
	, characterMng(Config.CharacterConfig)
	, connectionMng(Config.ConnectionConfig)
	, discordMng(Config.DiscordConfig)
	, mapMng(Config.MapConfig)
	, packetMng(Config.PacketConfig)
	, uiMng(Config.UIConfig)
{
	auto _ = Logger::PushPopModuleName("ClientModding");

	packetMng.Subscribe(PacketType::RCVD, "tit", [this](std::string& Packet) { on_PR_tit(Packet); });

	packetMng.Subscribe(PacketType::RCVD, "st", [this](std::string& Packet) { on_PR_st(Packet); });
	packetMng.Subscribe(PacketType::RCVD, "aa_st", [this](std::string& Packet) { on_PR_aa_st(Packet); });

	packetMng.Subscribe(PacketType::RCVD, "pst", [this](std::string& Packet) { on_PR_pst(Packet); });
	packetMng.Subscribe(PacketType::RCVD, "aa_pst", [this](std::string& Packet) { on_PR_aa_pst(Packet); });
}

bool ClientModding::Initialize()
{
	auto _ = Logger::PushPopModuleName("ClientModding");

	if (!ClassSearcher::Initialize())
		return false;

	if (TLBSWidgetHandler::getNtInstance() == nullptr)
		return false;

	if (TSceneManager::getNtInstance() == nullptr)
		return false;

	if (!characterMng.Initialize())
		return false;

	if (!connectionMng.Initialize())
		return false;

	if (!discordMng.Initialize())
		return false;

	if (!mapMng.Initialize())
		return false;

	if (!packetMng.Initialize())
		return false;

	if (!uiMng.Initialize())
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
	characterMng.Tick();
	connectionMng.Tick();
	discordMng.Tick();
	mapMng.Tick();
	packetMng.Tick();
	uiMng.Tick();
}

void ClientModding::on_PR_tit(std::string& packet)
{
	auto words = Split(packet, " ");
	std::string pseudo = words[2];
	discordMng.SetPseudonym(pseudo);
	discordMng.SetChannel(connectionMng.GetServChanManager().GetChannel());
}

void ClientModding::on_PR_st(std::string& packet)
{
	PR_st p(packet);
	if (!p.IsValid())
	{
		Logger::PushPopModuleName("ClientModding");
		Logger::Error("Packet [%s] is not valid", p.GetPacket().c_str());
		return;
	}

	uiMng.GetSpyHpMpManager().On_PR_st(p);
}

void ClientModding::on_PR_aa_st(std::string& packet)
{
	PR_aa_st p(packet);
	if (!p.IsValid())
	{
		Logger::PushPopModuleName("ClientModding");
		Logger::Error("Packet [%s] is not valid", p.GetPacket().c_str());
		return;
	}

	uiMng.GetSpyHpMpManager().On_PR_aa_st(p);
}

void ClientModding::on_PR_pst(std::string& packet)
{
	PR_pst p(packet);
	if (!p.IsValid())
	{
		Logger::PushPopModuleName("ClientModding");
		Logger::Error("Packet [%s] is not valid", p.GetPacket().c_str());
		return;
	}

	uiMng.GetSpyHpMpManager().On_PR_pst(p);
}

void ClientModding::on_PR_aa_pst(std::string& packet)
{
	PR_aa_pst p(packet);
	if (!p.IsValid())
	{
		Logger::PushPopModuleName("ClientModding");
		Logger::Error("Packet [%s] is not valid", p.GetPacket().c_str());
		return;
	}

	uiMng.GetSpyHpMpManager().On_PR_aa_pst(p);
}
