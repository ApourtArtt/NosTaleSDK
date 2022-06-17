#pragma once
#include "ClientModdingConfig.h"

#include "Api/Managers/CharacterManager/CharacterManager.h"
#include "Api/Managers/ConnectionManager/ConnectionManager.h"
#include "Api/Managers/DiscordManager/DiscordManager.h"
#include "Api/Managers/MapManager/MapManager.h"
#include "Api/Managers/GameFileManager/GameFileManager.h"
#include "Api/Managers/PacketManager/PacketManager.h"
#include "Api/Managers/UIManager/UIManager.h"

// ClientModding is the interface you should inherit from.
// This class is handling everything:
// - setuping widgets, managers
// - configuring widgets, managers
// - creating the event loop
class ClientModding
{
public:
	[[nodiscard]] explicit ClientModding(const ClientModdingConfig& Config) noexcept;
	virtual ~ClientModding() noexcept {}

	[[nodiscard]] bool IsReady() noexcept { return isReady; }
	void Run() noexcept;

	void OnShowNostaleSplash() noexcept;
	void OnFreeNostaleSplash() noexcept;

	void Tick() noexcept;

private:
	void on_PR_tit(std::string& packet) noexcept;
	void on_PR_st(std::string& packet) noexcept;
	void on_PR_aa_st(std::string& packet) noexcept;
	void on_PR_pst(std::string& packet) noexcept;
	void on_PR_aa_pst(std::string& packet) noexcept;

protected:
	[[nodiscard]] virtual bool beforeRun() noexcept { return true; }
	virtual void onShowNostaleSplash() noexcept {}
	virtual void onFreeNostaleSplash() noexcept {}
	virtual void tick() noexcept {}

	ClientModdingConfig config;
	bool isReady{ false };

	CharacterManager characterMng;
	ConnectionManager connectionMng;
	DiscordManager discordMng;
	MapManager mapMng;
	GameFileManager gameFileMng;
	PacketManager packetMng;
	UIManager uiMng;
};
