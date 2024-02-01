module;
export module TNosSndCmdList;
import TList;
import Callback;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
		struct TNosSndCmdList : public TList<struct TNosSndCmds*>
	{
		Properties::Logical::Callback callback;
	};
	static_assert(sizeof(TNosSndCmdList<TNosSndCmds*>) == 0x18, "TNosSndCmdList size isn't 0x18.");
	static_assert(sizeof(TNosSndCmdList<TNosSndCmds*>) <= 0x18, "TNosSndCmdList size is upper than 0x18.");
	static_assert(sizeof(TNosSndCmdList<TNosSndCmds*>) >= 0x18, "TNosSndCmdList size is lower than 0x18.");
#pragma pack(pop)
}