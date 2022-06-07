#pragma once
#include "../Properties/Graphical/WeaponGlowingStyle.h"
#pragma pack(push, 1)

class TMapPlayerObj // inherit btw
{
public:
	void setWeaponGlow(WeaponGlow WeaponGlow) { weaponGlow = WeaponGlow; }
	void setWeaponRarity(Rarity WeaponRarity) { weaponRarity = WeaponRarity; }
	void setWeaponUpgrade(Upgrade WeaponUpgrade) { weaponUpgrade = WeaponUpgrade; }

private:
	char uselessForNow[0x1C4];
	WeaponGlow weaponGlow; // 0x1C4;
	char uselessForNow2[0x31]; // 0x1D6
	Rarity weaponRarity; // 0x207
	Upgrade weaponUpgrade; // 0x208
	char unknown[0x7];
};
static_assert(sizeof(TMapPlayerObj) == 0x210, "TMapPlayerObj does not have a size of 0x210.");

#pragma pack(pop)
