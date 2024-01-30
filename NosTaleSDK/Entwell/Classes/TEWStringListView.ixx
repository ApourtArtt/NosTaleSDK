module;
export module TEWStringListView;
import TEWStringListViewCore;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWStringListView : public TEWStringListViewCore
	{
	};
	static_assert(sizeof(TEWStringListView) == 0xB0, "TEWStringListView size isn't 0xB0.");
	static_assert(sizeof(TEWStringListView) <= 0xB0, "TEWStringListView size is upper than 0xB0.");
	static_assert(sizeof(TEWStringListView) >= 0xB0, "TEWStringListView size is lower than 0xB0.");
#pragma pack(pop)
}