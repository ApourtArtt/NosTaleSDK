module;
export module TNTCItemDataList;
import TNTNonMemIntHeadList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCItemDataList : public TNTNonMemIntHeadList<void>
	{
	};
	static_assert(sizeof(TNTCItemDataList) == 0x10, "TNTCItemDataList does not have a size of 0x10.");
#pragma pack(pop)
}