#pragma once
#include <map>

typedef int32_t wingStyleId;
typedef int32_t wingLevel;
typedef int32_t wingId;
typedef int32_t auraId;
typedef std::map<wingLevel, wingId> levelToId;
typedef std::map<wingStyleId, levelToId> wingsMap;

class WingsManagerConfig
{
public:
	wingsMap AdditionalWings;
	levelToId AdditionalAuras;
};
