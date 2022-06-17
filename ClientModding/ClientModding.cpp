#include "ClientModding.h"
#include "MemoryHelper/HwndGetter.h"
#include "Utils/Split.h"
#include "Api/DelphiClasses/TLBSWidgetHandler.h"
#include "Api/DelphiClasses/TSceneManager.h"

ClientModding::ClientModding(const ClientModdingConfig& Config) noexcept
	: config(Config)
	, characterMng(Config.CharacterConfig)
	, connectionMng(Config.ConnectionConfig)
	, discordMng(Config.DiscordConfig)
	, mapMng(Config.MapConfig)
	, gameFileMng(Config.GameFileConfig)
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

void ClientModding::Run() noexcept
{
	auto _ = Logger::PushPopModuleName("ClientModding");

	if (!beforeRun())
	{
		Logger::Error("Unable to run");
		return;
	}
	Logger::Log("Now running...");


	Logger::Log("%s", NScliManager::GetConstString(276));
	Logger::Log("%s", NScliManager::GetConstString(277));
	Logger::Log("%s", NScliManager::GetConstString(278));
	Logger::Log("%s", NScliManager::GetConstString(279));
	Logger::Log("%s", NScliManager::GetConstString(280));
	Logger::Log("%s", NScliManager::GetConstString(281));
	Logger::Log("%s", NScliManager::GetConstString(282));
	Logger::Log("%s", NScliManager::GetConstString(283));
	Logger::Log("%s", NScliManager::GetConstString(284));
	Logger::Log("%s", NScliManager::GetConstString(285));
	Logger::Log("%s", NScliManager::GetConstString(286));
	Logger::Log("%s", NScliManager::GetConstString(4224));

	while (true)
	{
		Tick();
		Sleep(config.EventLoopDelay);
	}
}

void ClientModding::OnShowNostaleSplash() noexcept
{
	auto _ = Logger::PushPopModuleName("ClientModding");

	if (!ClassSearcher::Initialize())
		return;

	if (!gameFileMng.Initialize())
		return;

	if (!discordMng.Initialize())
		return;

	onShowNostaleSplash();

	Logger::Success("Successfully initialized");
}

void ClientModding::OnFreeNostaleSplash() noexcept
{
	auto _ = Logger::PushPopModuleName("ClientModding");

	if (!TLBSWidgetHandler::getNtInstance())
		return;

	if (!TSceneManager::getNtInstance())
		return;

	if (!characterMng.Initialize())
		return;

	if (!connectionMng.Initialize())
		return;

	if (!mapMng.Initialize())
		return;

	if (!packetMng.Initialize())
		return;

	if (!uiMng.Initialize())
		return;

	onFreeNostaleSplash();
	isReady = true;

	Logger::Success("Successfully initialized");
}

void ClientModding::Tick() noexcept
{
	characterMng.Tick();
	connectionMng.Tick();
	discordMng.Tick();
	mapMng.Tick();
	gameFileMng.Tick();
	packetMng.Tick();
	uiMng.Tick();
}

void ClientModding::on_PR_tit(std::string& packet) noexcept
{
	auto words = Split(packet, " ");
	std::string pseudo = words[2];
	discordMng.SetPseudonym(pseudo);
	discordMng.SetChannel(connectionMng.GetServChanManager().GetChannel());
}

void ClientModding::on_PR_st(std::string& packet) noexcept
{
	PR_st p(packet);
	if (!p.IsValid())
	{
		auto _ = Logger::PushPopModuleName("ClientModding");
		Logger::Error("Packet [%s] is not valid", p.GetPacket().c_str());
		return;
	}

	uiMng.GetSpyHpMpManager().On_PR_st(p);
}

void ClientModding::on_PR_aa_st(std::string& packet) noexcept
{
	PR_aa_st p(packet);
	if (!p.IsValid())
	{
		auto _ = Logger::PushPopModuleName("ClientModding");
		Logger::Error("Packet [%s] is not valid", p.GetPacket().c_str());
		return;
	}

	uiMng.GetSpyHpMpManager().On_PR_aa_st(p);
}

void ClientModding::on_PR_pst(std::string& packet) noexcept
{
	PR_pst p(packet);
	if (!p.IsValid())
	{
		auto _ = Logger::PushPopModuleName("ClientModding");
		Logger::Error("Packet [%s] is not valid", p.GetPacket().c_str());
		return;
	}

	uiMng.GetSpyHpMpManager().On_PR_pst(p);
}

void ClientModding::on_PR_aa_pst(std::string& packet) noexcept
{
	PR_aa_pst p(packet);
	if (!p.IsValid())
	{
		auto _ = Logger::PushPopModuleName("ClientModding");
		Logger::Error("Packet [%s] is not valid", p.GetPacket().c_str());
		return;
	}

	uiMng.GetSpyHpMpManager().On_PR_aa_pst(p);
}
