#pragma once
#include <string>
#include "discord.h"

class DiscordManagerConfig
{
public:
	bool Active{ false };
	discord::ClientId ApplicationId;
	std::string ApplicationName;
	std::string ImageName;
};
