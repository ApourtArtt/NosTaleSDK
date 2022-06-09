#include "SpManager.h"

SpManager::SpManager(const SpManagerConfig& Config) noexcept
    : Manager(Config, "SpManager")
    , auraMng(Config.AuraConfig)
    , wingMng(Config.WingConfig)
{}

bool SpManager::initialize() noexcept
{
    if (!auraMng.Initialize())
        return false;
    if (!wingMng.Initialize())
        return false;
    return true;
}

bool SpManager::unload() noexcept
{
    bool res = true;

    if (!auraMng.Unload())
        res = false;
    if (!wingMng.Unload())
        res = false;

    return res;
}

void SpManager::tick() noexcept
{}
