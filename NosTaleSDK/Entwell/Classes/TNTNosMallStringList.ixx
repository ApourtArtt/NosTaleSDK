module;
export module TNTNosMallStringList;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TNTNosMallStringList : public TList<void*>
	{
	};
	static_assert(sizeof(TNTNosMallStringList<void*>) == 0x10, "TNTNosMallStringList size isn't 0x10.");
	static_assert(sizeof(TNTNosMallStringList<void*>) <= 0x10, "TNTNosMallStringList size is upper than 0x10.");
	static_assert(sizeof(TNTNosMallStringList<void*>) >= 0x10, "TNTNosMallStringList size is lower than 0x10.");
#pragma pack(pop)
}