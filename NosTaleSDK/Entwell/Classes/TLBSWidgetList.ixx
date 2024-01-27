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
	static_assert(sizeof(TLBSWidgetList<struct TLBSWidget*>) == 0x10, "TLBSWidgetList does not have a size of 0x10.");
#pragma pack(pop)
}