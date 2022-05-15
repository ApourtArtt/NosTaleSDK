#include "DiscordManager.h"
#include <Windows.h>

DiscordManager::DiscordManager()
	: core(nullptr)
	, user()
	, started(false)
	, channel(-1)
	, gameActivity(DiscordGameActivity::AFK)
{
	activity.SetType(discord::ActivityType::Playing);
	activity.GetTimestamps().SetStart(time(0));
	activity.GetAssets().SetLargeImage("ditz_logo");
	activity.GetAssets().SetLargeText("Ditz");
}

DiscordManager::~DiscordManager()
{
	started = false;
	if (runner.joinable())
		runner.join();
	if (core)
		delete core;
}

void DiscordManager::Start()
{
	if (core)
		delete core;

	started = true;
	auto res = discord::Core::Create(858502310669582346, (uint64_t)discord::CreateFlags::Default, &core);
	if (res == discord::Result::Ok)
	{
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
				Sleep(500);
			}
			delete core;
			core = nullptr;
		});
	}
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
			/*
			
	AFK,
	FARM,
	ORGANIZE_RAID,
	PARTICIPATE_RAID,
	TRAIN_PET,
	FISH,
	COOK,
			*/
		// TODO: little image + text on hover
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
