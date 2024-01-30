module;
#include <stdint.h>
export module TNTNosMallPostItemList;
import TNTDataList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TNTNosMallPostItemList : public TNTDataList<void*>
	{
	};
	static_assert(sizeof(TNTNosMallPostItemList<void*>) == 0x10, "TNTNosMallPostItemList size isn't 0x10.");
	static_assert(sizeof(TNTNosMallPostItemList<void*>) <= 0x10, "TNTNosMallPostItemList size is upper than 0x10.");
	static_assert(sizeof(TNTNosMallPostItemList<void*>) >= 0x10, "TNTNosMallPostItemList size is lower than 0x10.");
#pragma pack(pop)
}