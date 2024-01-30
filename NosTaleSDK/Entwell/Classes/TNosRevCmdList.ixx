module;
export module TNosRevCmdList;
import TObject;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	struct TNosRevCmdList : public TObject
	{
		struct TList<struct TNosRevCmd*>* list;	// 0x004
		struct TStringList* packetArgs;			// 0x008
	};
	static_assert(sizeof(TNosRevCmdList) == 0xC, "TNosRevCmdList size isn't 0xC.");
	static_assert(sizeof(TNosRevCmdList) <= 0xC, "TNosRevCmdList size is upper than 0xC.");
	static_assert(sizeof(TNosRevCmdList) >= 0xC, "TNosRevCmdList size is lower than 0xC.");
#pragma pack(pop)
}