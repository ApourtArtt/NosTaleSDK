module;
#include <stdint.h>
export module TNTIntHeadList;
import TNTDataList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	template<class T>
	struct IntListElement
	{
		int32_t vnum;
		T value;
	};
	static_assert(sizeof(IntListElement<void*>) == 0x8, "IntListElement size isn't 0x8.");
	static_assert(sizeof(IntListElement<void*>) <= 0x8, "IntListElement size is upper than 0x8.");
	static_assert(sizeof(IntListElement<void*>) >= 0x8, "IntListElement size is lower than 0x8.");

	export template<class T>
		struct TNTIntHeadList : public TNTDataList<IntListElement<T>*>
	{
	};
	static_assert(sizeof(TNTIntHeadList<IntListElement<void*>*>) == 0x10, "TNTIntHeadList size isn't 0x10.");
	static_assert(sizeof(TNTIntHeadList<IntListElement<void*>*>) <= 0x10, "TNTIntHeadList size is upper than 0x10.");
	static_assert(sizeof(TNTIntHeadList<IntListElement<void*>*>) >= 0x10, "TNTIntHeadList size is lower than 0x10.");
#pragma pack(pop)
}