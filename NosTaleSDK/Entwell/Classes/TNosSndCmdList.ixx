module;
export module TNosSndCmdList;
import TObject;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	struct TNosSndCmdList : public TList<struct TNosSndCmds*>
	{
		char callback[8];
	};
	static_assert(sizeof(TNosSndCmdList) == 0x18, "TNosSndCmdList does not have a size of 0x18.");
#pragma pack(pop)
}