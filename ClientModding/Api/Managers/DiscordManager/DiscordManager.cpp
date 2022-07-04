#include "DiscordManager.h"

DiscordManager::DiscordManager(const DiscordManagerConfig& Config) noexcept
	: Manager(Config, "DiscordManager")
	, gameActivity(DiscordGameActivity::AFK)
{}

bool DiscordManager::initialize() noexcept
{
	if (!config.Active)
	{
		Logger::Log("Not activated");
		return true;
	}

	activity.SetType(discord::ActivityType::Playing);
	activity.GetTimestamps().SetStart(time(0));
	activity.GetAssets().SetLargeText(config.ApplicationName.c_str());
	activity.GetAssets().SetLargeImage(config.ImageName.c_str());

	if (discord::Core::Create(config.ApplicationId, static_cast<uint64_t>(discord::CreateFlags::Default), &core) != discord::Result::Ok)
	{
		Logger::Error("Failed creating Discord session");
		return false;
	}

	core->UserManager().OnCurrentUserUpdate.Connect([&]()
	{
		core->UserManager().GetCurrentUser(&user);
	});

	Logger::Success("Successfully initialized");
	return true;
}

bool DiscordManager::unload() noexcept
{
	started = false;
	if (core) [[likely]]
	{
		delete core;
		core = nullptr;
	}
	return true;
}

void DiscordManager::tick() noexcept
{
	if (!core)
		return;

	updateActivity();
	core->RunCallbacks();
}

void DiscordManager::updateActivity() noexcept
{
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
			activity.SetState("TODO_FARM");
			break;
		case DiscordGameActivity::ORGANIZE_RAID:
			activity.SetState("TODO_ORGANIZE_RAID");
			break;
		case DiscordGameActivity::PARTICIPATE_RAID:
			activity.SetState("TODO_PARTICIPATE_RAID");
			break;
		case DiscordGameActivity::TRAIN_PET:
			activity.SetState("TODO_TRAIN_PET");
			break;
		case DiscordGameActivity::FISH:
			activity.SetState("TODO_FISH");
			break;
		case DiscordGameActivity::COOK:
			activity.SetState("TODO_COOK");
			break;
		default:
			activity.SetState("Idle");
			break;
		}
	}

	core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
}
