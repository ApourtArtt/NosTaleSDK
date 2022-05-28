#pragma once
#include "Api/CustomClasses/MapCommon/MapCommon.h"
#include "Api/CustomClasses/Connection/Connection.h"

#include "Api/DelphiClasses/TLBSWidgetHandler.h"
#include "Api/DelphiClasses/TSceneManager.h"

#include "Api/DiscordManager/DiscordManager.h"
#include "Api/PacketManager/PacketManager.h"

class ClientModding
{
public:
	explicit ClientModding();
	virtual ~ClientModding();

	bool Initialize();
	void Run(unsigned int sleepTime = 10);

	void Tick();

private:
	void on_PR_tit(std::string& packet);

	Connection connection{};
	MapCommon mapCommon{};
	DiscordManager discordMng{};
	PacketManager packetMng{};

	TLBSWidgetHandler* ntWidgetHandler{ nullptr };
	TSceneManager* ntSceneMng{ nullptr };

	HWND hwnd{};

protected:
	virtual bool beforeRun() { return true; }
	virtual void tick() {}
};
