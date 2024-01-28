module;
export module TLBSBkFxList;
import TList;
import TLBSBkFxItem;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TLBSBkFxList : public TList<struct TLBSBkFxItem*>
	{
	};
	static_assert(sizeof(TLBSBkFxList<struct TLBSBkFxItem*>) == 0x10, "TLBSBkFxList does not have a size of 0x18C.");
#pragma pack(pop)
}