#pragma once
#include <map>

typedef int32_t wingStyleId, auraStyleId;
typedef int32_t wingLevel, auraLevel;
typedef int32_t wingId, auraId;
typedef std::map<wingLevel, wingId> levelToId;
typedef std::map<auraLevel, auraId> levelToId;
typedef std::map<wingStyleId, levelToId> wingsMap;

struct WingManagerConfig
{
	wingsMap AdditionalWings;
};
