module;
#include <stdint.h>
export module TLockOnTargetMarked;
import TLockOnTargetMarkedCore;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLockOnTargetMarked : public TLockOnTargetMarkedCore
	{
		char unknown13[4];			// 0x044
		int32_t timestamp2;			// 0x048
		uint32_t unknown14;			// 0x04C
		uint8_t unknown15;			// 0x050
		char unknown16[3];			// 0x051
	};
	static_assert(sizeof(TLockOnTargetMarked) == 0x54, "TLockOnTargetMarked size isn't 0x54.");
	static_assert(sizeof(TLockOnTargetMarked) <= 0x54, "TLockOnTargetMarked size is upper than 0x54.");
	static_assert(sizeof(TLockOnTargetMarked) >= 0x54, "TLockOnTargetMarked size is lower than 0x54.");
#pragma pack(pop)
}