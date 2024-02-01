module;
export module WeaponGlowing;
import Bgra;
import WeaponGlowingStyle;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct WeaponGlowing
	{
		Bgra secondaryColor;								// 0x000
		float secondarySize;								// 0x004
		Enumerations::WeaponGlowingStyle secondaryStyle;	// 0x008
		Bgra color;											// 0x009
		float size{ 0. };									// 0x00D
		Enumerations::WeaponGlowingStyle style;				// 0x011
	};
	static_assert(sizeof(WeaponGlowing) == 0x12, "WeaponGlowing size isn't 0x12.");
	static_assert(sizeof(WeaponGlowing) <= 0x12, "WeaponGlowing size is upper than 0x12.");
	static_assert(sizeof(WeaponGlowing) >= 0x12, "WeaponGlowing size is lower than 0x12.");
#pragma pack(pop)
}