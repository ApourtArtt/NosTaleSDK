#pragma once
#include <map>

typedef int32_t auraStyleId;
typedef int32_t auraLevel;
typedef int32_t auraId;
typedef std::map<auraLevel, auraId> levelToId;

struct AuraManagerConfig
{
	levelToId AdditionalAuras;
};
