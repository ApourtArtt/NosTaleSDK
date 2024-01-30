module;
export module TMapNpcObj;
import TMapMonsterObj;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapNpcObj : public TMapMonsterObj
	{
		struct NosTaleSDK::Entwell::Properties::Logical::String* name;	// 0x1D4
	};
	static_assert(sizeof(TMapNpcObj) == 0x1D8, "TMapNpcObj size isn't 0x1D8.");
	static_assert(sizeof(TMapNpcObj) <= 0x1D8, "TMapNpcObj size is upper than 0x1D8.");
	static_assert(sizeof(TMapNpcObj) >= 0x1D8, "TMapNpcObj size is lower than 0x1D8.");
#pragma pack(pop)
}