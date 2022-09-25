#include "DiscordManager.h"

DiscordManager::DiscordManager(const DiscordManagerConfig& Config) noexcept
	: Manager(Config, "DiscordManager")
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
	activity.SetDetails(line1.c_str());
	activity.SetState(line2.c_str());
	activity.GetAssets().SetSmallText(littleImageHover.c_str());
	activity.GetAssets().SetSmallImage(littleImageName.c_str());
	activity.GetAssets().SetLargeText(bigImageHover.c_str());
	activity.GetAssets().SetLargeImage(bigImageName.c_str());

	core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
}
