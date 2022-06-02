#pragma once
#include <map>
#include "Bgra.h"

enum class WeaponGlowingStyle : int8_t
{
	NO_GLOWING = 0,
	SLOW_CIRCULAR = 1,
	FAST_CIRCULAR = 2,
	PROGRESSIVE = 3,
	ALWAYS = 4,
};

typedef int8_t Upgrade;
typedef int8_t Rarity;

#pragma pack(push, 1)
class WeaponGlow
{
public:
	Bgra SecondaryGlowColor;
	float SecondaryGlowSize{ 0. };
	WeaponGlowingStyle SecondaryGlowStyle{ WeaponGlowingStyle::NO_GLOWING };
	Bgra PrimaryGlowColor;
	float PrimaryGlowSize{ 0. };
	WeaponGlowingStyle PrimaryGlowStyle{ WeaponGlowingStyle::NO_GLOWING };
};
#pragma pack(pop)
