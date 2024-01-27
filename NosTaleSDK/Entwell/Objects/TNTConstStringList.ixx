module;
export module TNTConstStringList;
import TNTIntHeadList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIntHeadList<char*> TNTConstStringList
	{
	};
	static_assert(sizeof(TNTConstStringList) == 0x10, "TNTConstStringList does not have a size of 0x10.");
#pragma pack(pop)
}