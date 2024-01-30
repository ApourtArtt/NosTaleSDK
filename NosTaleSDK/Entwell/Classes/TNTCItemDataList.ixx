module;
export module TNTCItemDataList;
import TNTNonMemIntHeadList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCItemDataList : public TNTNonMemIntHeadList<void>
	{
	};
	static_assert(sizeof(TNTCItemDataList) == 0x10, "TNTCItemDataList size isn't 0x10.");
	static_assert(sizeof(TNTCItemDataList) <= 0x10, "TNTCItemDataList size is upper than 0x10.");
	static_assert(sizeof(TNTCItemDataList) >= 0x10, "TNTCItemDataList size is lower than 0x10.");
#pragma pack(pop)
}