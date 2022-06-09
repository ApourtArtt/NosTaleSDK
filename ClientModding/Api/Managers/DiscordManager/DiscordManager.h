#pragma once
#include "../Manager.h"
#pragma comment(lib, "discord_game_sdk.dll.lib")
#include "DiscordConfig.h"

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

class DiscordManager : public Manager<DiscordManagerConfig>
{
public:
	[[nodiscard]] explicit DiscordManager(const DiscordManagerConfig& Config) noexcept;

	void Start() noexcept { started = true; }
	void Stop() noexcept { started = false; }

	void SetPseudonym(const std::string& Pseudonym) noexcept { pseudonym = Pseudonym; }
	void SetChannel(short Channel) noexcept { channel = Channel; }
	void SetActivity(DiscordGameActivity GameActivity) noexcept { gameActivity = GameActivity; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	void updateActivity() noexcept;

	discord::Core* core{ nullptr };
	discord::User user{};
	discord::Activity activity{};

	bool started{ false };

	std::string pseudonym;
	short channel{ -1 };
	DiscordGameActivity gameActivity{ DiscordGameActivity::AFK };
};