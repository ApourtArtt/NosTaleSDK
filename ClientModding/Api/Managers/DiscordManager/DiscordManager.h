#pragma once
#include "../Manager.h"
#pragma comment(lib, "discord_game_sdk.dll.lib")
#include "DiscordConfig.h"

class DiscordManager : public Manager<DiscordManagerConfig>
{
public:
	[[nodiscard]] explicit DiscordManager(const DiscordManagerConfig& Config) noexcept;

	void Start() noexcept { started = true; }
	void Stop() noexcept { started = false; }

	void SetBigImage(const std::string& ImageId) noexcept { bigImageName = ImageId; }
	void SetBigImageHover(const std::string& Text) noexcept { bigImageHover = Text; }
	void SetLittleImage(const std::string& ImageId) noexcept { littleImageName = ImageId; }
	void SetLittleImageHover(const std::string& Text) noexcept { littleImageHover = Text; }
	void SetLine1(const std::string& Text) noexcept { line1 = Text; }
	void SetLine2(const std::string& Text) noexcept { line2 = Text; }

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	void updateActivity() noexcept;

	discord::Core* core{ nullptr };
	discord::User user{};
	discord::Activity activity{};

	bool started{ false };

	std::string bigImageName;
	std::string bigImageHover;
	std::string littleImageName;
	std::string littleImageHover;
	std::string line1, line2;
};