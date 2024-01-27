module;
export module TEWStringListView;
import TEWStringListViewCore;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWStringListView : public TEWStringListViewCore
	{
	};
	static_assert(sizeof(TEWStringListView) == 0xB0, "TEWStringListView does not have a size of 0xB0.");
#pragma pack(pop)
}