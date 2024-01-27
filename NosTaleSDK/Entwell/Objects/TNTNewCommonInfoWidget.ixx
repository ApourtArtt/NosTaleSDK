module;
#include <stdint.h>
export module TNTNewCommonInfoWidget;
import TLBSWidget;
import TNTCommonInfoBoard;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNewCommonInfoWidget : public TLBSWidget
	{
		char unknown3[4];			// 0x24 2 int16_t, with left being right - 1 and right being number of opened TNTCommonInfoBoard
		int sizeOfFollowingArray;	// 0x28
		TNTCommonInfoBoard** arr;	// 0x2C -- Ugly, make a DelphiDynArray class template and use it that way - note, 00 ref count 04 size 08 actual array
		char unknown4[28];			// 0x30 no clue
		// 0x44 : TNTItemList
	};
	static_assert(sizeof(TNTNewCommonInfoWidget) == 0x4C, "TNTNewCommonInfoWidget does not have a size of 0x4C");
#pragma pack(pop)
}