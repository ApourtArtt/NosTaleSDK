module;
export module TNosRevCmdList;
import TObject;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	struct TNosRevCmdList : public TObject
	{
		struct TList<struct TNosRevCmd*>* list;	// 0x04
		struct TStringList* packetArgs;	// 0x08
	};
	static_assert(sizeof(TNosRevCmdList) == 0xC, "TNosRevCmdList does not have a size of 0xC.");
#pragma pack(pop)
}