module;
export module TLBSMultiTextureList;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSMultiTextureList : public TList<void*>
	{
	};
	static_assert(sizeof(TLBSMultiTextureList) == 0x10, "TLBSMultiTextureList does not have a size of 0x10.");
#pragma pack(pop)
}