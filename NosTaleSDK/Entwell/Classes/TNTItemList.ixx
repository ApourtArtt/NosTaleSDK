module;
export module TNTItemList;
import TNTDataList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTItemList : public TNTDataList<struct Item>
	{

		char uknown[8];
	};
	static_assert(sizeof(TNTItemList) == 0x18, "TNTItemList does not have a size of 0x18.");
#pragma pack(pop)
}