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

	export template<class T>
	struct TNTIntHeadList : public TNTDataList<IntListElement<T>*>
	{
	};
	static_assert(sizeof(TNTIntHeadList<IntListElement<void*>*>) == 0x10, "TNTIntHeadList does not have a size of 0x10.");
#pragma pack(pop)
}