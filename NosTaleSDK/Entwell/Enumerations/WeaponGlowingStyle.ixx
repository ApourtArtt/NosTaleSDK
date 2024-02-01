module;
#include <stdint.h>
export module WeaponGlowingStyle;

namespace NosTaleSDK::Entwell::Enumerations
{
#pragma pack(push, 1)
	export enum class WeaponGlowingStyle : uint8_t
	{
		NONE = 0,
		SLOW = 1,
		FAST = 2,
		PROGRESSIVE = 3,
		ALWAYS = 4
	};
#pragma pack(pop)
}