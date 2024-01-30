module;
export module TNTNonMemIntHeadList;
import TNTIntHeadList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<class T>
		struct TNTNonMemIntHeadList : public TNTIntHeadList<T>
	{
	};
	static_assert(sizeof(TNTNonMemIntHeadList<void*>) == 0x10, "TNTNonMemIntHeadList size isn't 0x10.");
	static_assert(sizeof(TNTNonMemIntHeadList<void*>) <= 0x10, "TNTNonMemIntHeadList size is upper than 0x10.");
	static_assert(sizeof(TNTNonMemIntHeadList<void*>) >= 0x10, "TNTNonMemIntHeadList size is lower than 0x10.");
#pragma pack(pop)
}