module;
#include <stdint.h>
export module WeaponGlowingStyle;

namespace NosTaleSDK::Entwell::Enumerations
{
#pragma pack(push, 1)
	export enum class WeaponGlowingStyle : uint8_t
	{
		None = 0,
		Slow = 1,
		Fast = 2,
		Progressive = 3,
		Always = 4
	};
#pragma pack(pop)
}