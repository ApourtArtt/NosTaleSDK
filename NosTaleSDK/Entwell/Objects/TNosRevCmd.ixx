module;
export module TNosRevCmd;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNosRevCmd : public TObject
	{
		char unknown[4];				// 0x04
		void* handler;				    // 0x08
		struct TNTUnitManager* unitManager;    // 0x0C
		char* packet;					// 0x10
	};
	static_assert(sizeof(TNosRevCmd) == 0x14, "TNosRevCmd does not have a size of 0x14.");
#pragma pack(pop)
}