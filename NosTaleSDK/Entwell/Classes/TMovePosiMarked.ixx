module;
export module TMovePosiMarked;
import TLBSBkFxItem;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMovePosiMarked : public TLBSBkFxItem
	{
		bool isActive;					// 0x030
		char unknown10[3];				// 0x031
		struct TMapPlayerObj* entity;	// 0x034
	};
	static_assert(sizeof(TMovePosiMarked) == 0x38, "TMovePosiMarked size isn't 0x38.");
	static_assert(sizeof(TMovePosiMarked) <= 0x38, "TMovePosiMarked size is upper than 0x38.");
	static_assert(sizeof(TMovePosiMarked) >= 0x38, "TMovePosiMarked size is lower than 0x38.");
#pragma pack(pop)
}