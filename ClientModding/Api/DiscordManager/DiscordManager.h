#pragma once
#pragma comment(lib, "discord_game_sdk.dll.lib")
#include "DiscordConfig.h"
#include <thread>
#include <mutex>

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

class DiscordManager
{
public:
	DiscordManager(const DiscordManagerConfig& Config);
	~DiscordManager();

	bool Start();
	void Stop();

	void SetPseudonym(const std::string& Pseudonym);
	void SetChannel(short Channel);
	void SetActivity(DiscordGameActivity Activity);

private:
	void updateActivity();

	DiscordManagerConfig config;

	discord::Core* core{ nullptr };
	discord::User user{};
	discord::Activity activity{};

	std::thread runner;
	bool started{ false };

	std::string pseudonym;
	short channel{ -1 };
	DiscordGameActivity gameActivity{ DiscordGameActivity::AFK };
};