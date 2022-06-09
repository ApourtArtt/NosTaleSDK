#include "CharacterManager.h"

CharacterManager::CharacterManager(const CharacterManagerConfig& Config) noexcept
	: Manager(Config, "CharacterManager")
	, stuffMng(Config.StuffConfig)
	, interactionMng(Config.InteractionConfig)
{}

bool CharacterManager::initialize() noexcept
{
	if (!stuffMng.Initialize())
		return false;

	if (!interactionMng.Initialize())
		return false;

	return true;
}

bool CharacterManager::unload() noexcept
{
	bool res = true;

	if (!stuffMng.Initialize())
		res = false;

	if (!interactionMng.Initialize())
		res = false;

	return res;
}

void CharacterManager::tick() noexcept
{
	stuffMng.Tick();
	interactionMng.Tick();
}
