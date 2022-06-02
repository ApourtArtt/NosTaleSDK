#pragma once
#include "../Properties/Graphical/WeaponGlowingStyle.h"
#pragma pack(push, 1)

class TMapPlayerObj // inherit btw
{
public:
	void setWeaponGlow(WeaponGlow WeaponGlow) { weaponGlow = WeaponGlow; }

private:
	char uselessForNow[0x1C4];
	WeaponGlow weaponGlow; // 0x1C4;
};
static_assert(sizeof(TMapPlayerObj) == 0x1D6, "TMapPlayerObj does not have a size of 0x1D6.");

#pragma pack(pop)