#pragma once
#include "ClientModdingConfig.h"

#include "Api/CustomClasses/MapCommon/MapCommon.h"
#include "Api/CustomClasses/Connection/Connection.h"

#include "Api/DelphiClasses/TLBSWidgetHandler.h"
#include "Api/DelphiClasses/TSceneManager.h"

#include "Api/DiscordManager/DiscordManager.h"
#include "Api/Hooks/WingsManager/WingsManager.h"
#include "Api/PacketManager/PacketManager.h"


// ClientModding is the interface you should inherit from.
// This class is handling everything:
// - setuping widgets, managers
// - configuring widgets, managers
// - creating the event loop
class ClientModding
{
public:
	explicit ClientModding(const ClientModdingConfig& Config);
	virtual ~ClientModding();

	bool Initialize();
	void Run();

	void Tick();

private:
	void on_PR_tit(std::string& packet);

	HWND hwnd{};

protected:
	virtual bool beforeRun() { return true; }
	virtual void tick() {}

	ClientModdingConfig config;

	Connection connection{};
	MapCommon mapCommon{};
	DiscordManager discordMng;
	PacketManager packetMng{};

	WingsManager wingsMng;

	TLBSWidgetHandler* ntWidgetHandler{ nullptr };
	TSceneManager* ntSceneMng{ nullptr };
};
