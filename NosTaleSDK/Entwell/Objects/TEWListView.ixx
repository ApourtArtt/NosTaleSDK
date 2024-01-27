module;
export module TEWListView;
import TEWStringListView;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWListView : public TEWStringListView
	{
		char unknown15[0xC8 - 0xB0];
	};
	static_assert(sizeof(TEWListView) == 0xC8, "TEWListView does not have a size of 0xC8.");
#pragma pack(pop)
}