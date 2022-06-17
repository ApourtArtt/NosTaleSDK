#pragma once
#include "Api/Managers/CharacterManager/CharacterConfig.h"
#include "Api/Managers/ConnectionManager/ConnectionConfig.h"
#include "Api/Managers/DiscordManager/DiscordConfig.h"
#include "Api/Managers/MapManager/MapConfig.h"
#include "Api/Managers/GameFileManager/GameFileConfig.h"
#include "Api/Managers/PacketManager/PacketConfig.h"
#include "Api/Managers/UIManager/UIConfig.h"

struct ClientModdingConfig
{
	CharacterManagerConfig CharacterConfig;
	ConnectionManagerConfig ConnectionConfig;
	DiscordManagerConfig DiscordConfig;
	MapManagerConfig MapConfig;
	GameFileManagerConfig GameFileConfig;
	PacketManagerConfig PacketConfig;
	UIManagerConfig UIConfig;
	
	unsigned int EventLoopDelay{ 10 };
};
