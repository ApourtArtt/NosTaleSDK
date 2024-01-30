module;
export module TNTNosMallSelectedItemList;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TNTNosMallSelectedItemList : public TList<void*>
	{
	};
	static_assert(sizeof(TNTNosMallSelectedItemList<void*>) == 0x10, "TNTNosMallSelectedItemList size isn't 0x10.");
	static_assert(sizeof(TNTNosMallSelectedItemList<void*>) <= 0x10, "TNTNosMallSelectedItemList size is upper than 0x10.");
	static_assert(sizeof(TNTNosMallSelectedItemList<void*>) >= 0x10, "TNTNosMallSelectedItemList size is lower than 0x10.");
#pragma pack(pop)
}