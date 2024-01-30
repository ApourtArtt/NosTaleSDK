module;
export module TLockOnTargetMarkedCore;
import TLBSBkFxItem;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLockOnTargetMarkedCore : public TLBSBkFxItem
	{
		uint8_t unknown10;				// 0x030
		char unknown11[3];				// 0x031
		struct TMapNpcObj* target;		// 0x034
		bool isActive;					// 0x038
		char unknown12[3];				// 0x039
		float targetHeight;				// 0x03C
		struct TMapPlayerObj* entity;	// 0x040
	};
	static_assert(sizeof(TLockOnTargetMarkedCore) == 0x44, "TLockOnTargetMarkedCore size isn't 0x44.");
	static_assert(sizeof(TLockOnTargetMarkedCore) <= 0x44, "TLockOnTargetMarkedCore size is upper than 0x44.");
	static_assert(sizeof(TLockOnTargetMarkedCore) >= 0x44, "TLockOnTargetMarkedCore size is lower than 0x44.");
#pragma pack(pop)
}