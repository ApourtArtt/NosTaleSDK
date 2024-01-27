module;
export module TMapNpcObj;
import TMapMonsterObj;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapNpcObj : public TMapMonsterObj
	{
		char* pseudonym;	// 0x1D0 Delphi Ref counter Str
	};
	static_assert(sizeof(TMapNpcObj) == 0x1D8, "TMapNpcObj does not have a size of 0x1D8.");
#pragma pack(pop)
}