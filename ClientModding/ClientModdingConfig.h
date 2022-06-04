#pragma once
#include "Api/DiscordManager/DiscordConfig.h"
#include "Api/Hooks/WingsManager/WingsConfig.h"
#include "Api/Hooks/StuffManager/StuffConfig.h"
#include "Api/Hooks/UIManager/UIConfig.h"

class ClientModdingConfig
{
public:
	// Configure the Discord SDK
	DiscordManagerConfig DiscordConfig;
	// Configure the wings manager
	WingsManagerConfig WingsConfig;
	// Configure the stuff manager
	StuffManagerConfig StuffConfig;
	// Configure the UI manager
	UIManagerConfig UIConfig;
	
	// Delay between two iterations of the event loop
	unsigned int EventLoopDelay{ 10 };
};
