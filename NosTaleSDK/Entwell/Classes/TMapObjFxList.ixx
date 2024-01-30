module;
export module TMapObjFxList;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TMapObjFxList : public TList<struct TMapObjFxItem*>
	{
	};
	static_assert(sizeof(TMapObjFxList<struct TMapObjFxItem*>) == 0x10, "TMapObjFxList size isn't 0x10.");
	static_assert(sizeof(TMapObjFxList<struct TMapObjFxItem*>) <= 0x10, "TMapObjFxList size is upper than 0x10.");
	static_assert(sizeof(TMapObjFxList<struct TMapObjFxItem*>) >= 0x10, "TMapObjFxList size is lower than 0x10.");
#pragma pack(pop)
}