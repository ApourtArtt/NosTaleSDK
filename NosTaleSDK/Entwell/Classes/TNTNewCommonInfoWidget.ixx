module;
export module TNTNewCommonInfoWidget;
import TLBSWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewCommonInfoWidget : public TLBSWidget
	{
		char unknown5[4];					// 0x024 2 int16_t, with left being right - 1 and right being number of opened TNTCommonInfoBoard
		int sizeOfFollowingArray;			// 0x028
		struct TNTCommonInfoBoard** arr;	// 0x02C -- Ugly, make a DelphiDynArray class template and use it that way - note, 00 ref count 04 size 08 actual array
		char unknown6[28];					// 0x030 no clue
	};
	static_assert(sizeof(TNTNewCommonInfoWidget) == 0x4C, "TNTNewCommonInfoWidget size isn't 0x4C.");
	static_assert(sizeof(TNTNewCommonInfoWidget) <= 0x4C, "TNTNewCommonInfoWidget size is upper than 0x4C.");
	static_assert(sizeof(TNTNewCommonInfoWidget) >= 0x4C, "TNTNewCommonInfoWidget size is lower than 0x4C.");
#pragma pack(pop)
}