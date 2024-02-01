module;
export module TDowsingArrowWidget;
import TEWControlWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	template<typename T> struct TNTIntHeadList;
	export struct TDowsingArrowWidget : public TEWControlWidget
	{
		TNTIntHeadList<void*>* list;	// 0x068
	};
	static_assert(sizeof(TDowsingArrowWidget) == 0x6C, "TDowsingArrowWidget size isn't 0x6C.");
	static_assert(sizeof(TDowsingArrowWidget) <= 0x6C, "TDowsingArrowWidget size is upper than 0x6C.");
	static_assert(sizeof(TDowsingArrowWidget) >= 0x6C, "TDowsingArrowWidget size is lower than 0x6C.");

#pragma pack(pop)
}