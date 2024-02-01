module;
export module TLBSWidgetList;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TLBSWidgetList : public TList<struct TLBSWidget*>
	{
	};
	static_assert(sizeof(TLBSWidgetList<TLBSWidget*>) == 0x10, "TLBSWidgetList size isn't 0x10.");
	static_assert(sizeof(TLBSWidgetList<TLBSWidget*>) <= 0x10, "TLBSWidgetList size is upper than 0x10.");
	static_assert(sizeof(TLBSWidgetList<TLBSWidget*>) >= 0x10, "TLBSWidgetList size is lower than 0x10.");
#pragma pack(pop)
}