module;
#include <stdint.h>
export module TNTNosMallSlipItemList;
import TNTDataList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TNTNosMallSlipItemList : public TNTDataList<void*>
	{
	};
	static_assert(sizeof(TNTNosMallSlipItemList<void*>) == 0x10, "TNTNosMallSlipItemList size isn't 0x10.");
	static_assert(sizeof(TNTNosMallSlipItemList<void*>) <= 0x10, "TNTNosMallSlipItemList size is upper than 0x10.");
	static_assert(sizeof(TNTNosMallSlipItemList<void*>) >= 0x10, "TNTNosMallSlipItemList size is lower than 0x10.");
#pragma pack(pop)
}