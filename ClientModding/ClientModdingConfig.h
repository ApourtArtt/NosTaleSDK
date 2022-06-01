#pragma once
#include "Api/DiscordManager/DiscordConfig.h"
#include "Api/Hooks/WingsManager/WingsConfig.h"

class ClientModdingConfig
{
public:
	// Configure the Discord SDK
	DiscordManagerConfig DiscordConfig;
	// Configure the wings manager
	WingsManagerConfig WingsConfig;
	
	// Delay between two iterations of the event loop
	unsigned int EventLoopDelay{ 10 };
};
