module;
export module TLBSMultiTextureList;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TLBSMultiTextureList : public TList<struct TLBSMultiTextureCache*>
	{
	};
	static_assert(sizeof(TLBSMultiTextureList<struct TLBSMultiTextureCache*>) == 0x10, "TLBSMultiTextureList size isn't 0x10.");
	static_assert(sizeof(TLBSMultiTextureList<struct TLBSMultiTextureCache*>) <= 0x10, "TLBSMultiTextureList size is upper than 0x10.");
	static_assert(sizeof(TLBSMultiTextureList<struct TLBSMultiTextureCache*>) >= 0x10, "TLBSMultiTextureList size is lower than 0x10.");
#pragma pack(pop)
}