#pragma once
#include "ClientModdingConfig.h"

#include "Api/Managers/CharacterManager/CharacterManager.h"
#include "Api/Managers/ConnectionManager/ConnectionManager.h"
#include "Api/Managers/DiscordManager/DiscordManager.h"
#include "Api/Managers/MapManager/MapManager.h"
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
	explicit ClientModding(const ClientModdingConfig& Config);
	virtual ~ClientModding() {}

	bool Initialize();
	void Run();

	void Tick();

private:
	void on_PR_tit(std::string& packet);
	void on_PR_st(std::string& packet);
	void on_PR_aa_st(std::string& packet);
	void on_PR_pst(std::string& packet);
	void on_PR_aa_pst(std::string& packet);

protected:
	virtual bool beforeRun() { return true; }
	virtual void tick() {}

	ClientModdingConfig config;

	CharacterManager characterMng;
	ConnectionManager connectionMng;
	DiscordManager discordMng;
	MapManager mapMng;
	PacketManager packetMng;
	UIManager uiMng;
};
