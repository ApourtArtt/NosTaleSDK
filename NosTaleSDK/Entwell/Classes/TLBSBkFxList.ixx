module;
export module TLBSBkFxList;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TLBSBkFxList : public TList<struct TLBSBkFxItem*>
	{
	};
	static_assert(sizeof(TLBSBkFxList<struct TLBSBkFxItem*>) == 0x10, "TLBSBkFxList size isn't 0x10.");
	static_assert(sizeof(TLBSBkFxList<struct TLBSBkFxItem*>) <= 0x10, "TLBSBkFxList size is upper than 0x10.");
	static_assert(sizeof(TLBSBkFxList<struct TLBSBkFxItem*>) >= 0x10, "TLBSBkFxList size is lower than 0x10.");
#pragma pack(pop)
}