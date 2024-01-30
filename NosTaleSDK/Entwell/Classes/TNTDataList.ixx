module;
#include <cstdint>
export module TNTDataList;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<class T>
		struct TNTDataList : public TList<T>
	{
	};
	static_assert(sizeof(TNTDataList<void*>) == 0x10, "TNTDataList size isn't 0x10.");
	static_assert(sizeof(TNTDataList<void*>) <= 0x10, "TNTDataList size is upper than 0x10.");
	static_assert(sizeof(TNTDataList<void*>) >= 0x10, "TNTDataList size is lower than 0x10.");

#pragma pack(pop)
}
