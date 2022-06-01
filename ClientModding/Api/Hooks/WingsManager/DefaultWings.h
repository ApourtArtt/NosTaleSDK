#pragma once
#include "WingsConfig.h"

constexpr wingLevel ARENA_WINNER_SKELETON_LEVEL = 96;
constexpr wingLevel ARENA_WINNER_WINGS_LEVEL = 97;
constexpr wingId ARENA_WINNER_SKELETON_ID = 0xF77;
constexpr wingId ARENA_WINNER_WINGS_ID = 0xF78;

constexpr wingStyleId NO_SKIN = 0;
constexpr wingStyleId DEVIL_WING = 2;

std::map<wingStyleId, levelToId> defaultWings =
{
	{ NO_SKIN, levelToId
		{
			{ 1, 1200 },
			{ 2, 1200 },
			{ 3, 1201 },
			{ 4, 1201 },
			{ 5, 1202 },
			{ 6, 1202 },
			{ 7, 1203 },
			{ 8, 1203 },
			{ 9, 1204 },
			{ 10, 1204 },
			{ 11, 1205 },
			{ 12, 1206 },
			{ 13, 1207 },
			{ 14, 1208 },
			{ 15, 1209 },
			{ 16, 1209 },
			{ 17, 1209 },
			{ 18, 1209 },
			{ 19, 1209 },
			{ 20, 1209 },
		}
	},
	{ DEVIL_WING, levelToId
		{
			{ 1, 1220 },
			{ 2, 1220 },
			{ 3, 1221 },
			{ 4, 1221 },
			{ 5, 1222 },
			{ 6, 1222 },
			{ 7, 1223 },
			{ 8, 1223 },
			{ 9, 1224 },
			{ 10, 1224 },
			{ 11, 1225 },
			{ 12, 1226 },
			{ 13, 1227 },
			{ 14, 1228 },
			{ 15, 1229 },
			{ 16, 1229 },
			{ 17, 1229 },
			{ 18, 1229 },
			{ 19, 1229 },
			{ 20, 1229 },
		}
	},
};