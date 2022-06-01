#include "DiscordManager.h"
#include <Windows.h>

DiscordManager::DiscordManager(const DiscordManagerConfig& Config)
	: config(Config)
	, core(nullptr)
	, user()
	, started(false)
	, channel(-1)
	, gameActivity(DiscordGameActivity::AFK)
{
	if (config.Active)
	{
		activity.SetType(discord::ActivityType::Playing);
		activity.GetTimestamps().SetStart(time(0));
		activity.GetAssets().SetLargeText(config.ApplicationName.c_str());
		activity.GetAssets().SetLargeImage(config.ImageName.c_str());
	}
}

DiscordManager::~DiscordManager()
{
	started = false;
	if (runner.joinable()) [[likely]]
		runner.join();
	if (core) [[likely]]
	{
		delete core;
		core = nullptr;
	}
}

bool DiscordManager::Start()
{
	if (!config.Active) [[unlikely]]
		return true; // Because we want this program to run

	if (started) [[unlikely]]
		return false;

	if (core) [[likely]]
	{
		delete core;
		core = nullptr;
	}

	started = true;
	auto res = discord::Core::Create(config.ApplicationId, static_cast<uint64_t>(discord::CreateFlags::Default), &core);
	if (res != discord::Result::Ok)
		return false;

	runner = std::thread([&]
	{
		core->UserManager().OnCurrentUserUpdate.Connect([&]()
		{
			core->UserManager().GetCurrentUser(&user);
		});

		updateActivity();
		while (started)
		{
			core->RunCallbacks();
			Sleep(1000);
		}

		delete core;
		core = nullptr;
	});
	return true;
}

void DiscordManager::Stop()
{
	started = false;
}

void DiscordManager::SetPseudonym(const std::string& Pseudonym)
{
	pseudonym = Pseudonym;
	updateActivity();
}

void DiscordManager::SetChannel(short Channel)
{
	channel = Channel;
	updateActivity();
}

void DiscordManager::SetActivity(DiscordGameActivity Activity)
{
	gameActivity = Activity;
	updateActivity();
}

void DiscordManager::updateActivity()
{
	if (!core)
		return;

	if (pseudonym.empty() || channel == -1)
	{
		activity.SetDetails("Logging in...");
		activity.SetState("");
		// TODO: little image + text on hover
	}
	else
	{
		std::string detail = pseudonym + " Ch." + std::to_string(channel);
		activity.SetDetails(detail.c_str());

		switch (gameActivity)
		{
		case DiscordGameActivity::AFK:
			activity.SetState("Idle");
			break;
		case DiscordGameActivity::FARM:

			break;
		case DiscordGameActivity::ORGANIZE_RAID:

			break;
		case DiscordGameActivity::PARTICIPATE_RAID:

			break;
		case DiscordGameActivity::TRAIN_PET:

			break;
		case DiscordGameActivity::FISH:

			break;
		case DiscordGameActivity::COOK:

			break;
		default:
			activity.SetState("Idle");
			break;
		}
	}

	core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
}
