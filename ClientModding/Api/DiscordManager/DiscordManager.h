#pragma once
#pragma comment(lib, "discord_game_sdk.dll.lib")
#include "discord.h"
#include <thread>
#include <mutex>

/**
 * @brief Discord RPC activity.
 */
enum class DiscordGameActivity
{
	AFK,
	FARM,
	ORGANIZE_RAID,
	PARTICIPATE_RAID,
	TRAIN_PET,
	FISH,
	COOK,
};

/**
 * @brief Class for the discord RPC.
 */
class DiscordManager
{
public:
	DiscordManager();
	~DiscordManager();

	bool Start();
	void Stop();

	void SetPseudonym(const std::string& Pseudonym);
	void SetChannel(short Channel);
	void SetActivity(DiscordGameActivity Activity);

private:
	void updateActivity();

	discord::Core* core;
	discord::User user;
	discord::Activity activity;

	std::thread runner;
	bool started;

	std::string pseudonym;
	short channel;
	DiscordGameActivity gameActivity;
};