module;
export module TNTConstStringList;
import TNTIntHeadList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIntHeadList<char*> TNTConstStringList
	{
	};
	static_assert(sizeof(TNTConstStringList) == 0x10, "TNTCommonInfoBoard size isn't 0x10.");
	static_assert(sizeof(TNTConstStringList) <= 0x10, "TNTCommonInfoBoard size is upper than 0x10.");
	static_assert(sizeof(TNTConstStringList) >= 0x10, "TNTCommonInfoBoard size is lower than 0x10.");
#pragma pack(pop)
}