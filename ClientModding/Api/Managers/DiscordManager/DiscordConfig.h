#pragma once
#include <string>
#include "discord.h"

struct DiscordManagerConfig
{
	bool Active{ false };
	discord::ClientId ApplicationId;
};
