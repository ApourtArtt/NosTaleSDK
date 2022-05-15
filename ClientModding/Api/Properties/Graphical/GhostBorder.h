#pragma once
#include <stdint.h>
#pragma pack(push, 1)

// TODO: Add documentation

class GhostBorder
{
public:
	GhostBorder()
		: GhostBorder(0, 0, 0, 0)
	{}

	GhostBorder(int16_t LeftGap, int16_t TopGap, int16_t RightGap, int16_t BotGap)
		: leftGap(LeftGap)
		, topGap(TopGap)
		, rightGap(RightGap)
		, botGap(BotGap)
	{}

private:
	int16_t leftGap;
	int16_t topGap;
	int16_t rightGap;
	int16_t botGap;
};

#pragma pack(pop)