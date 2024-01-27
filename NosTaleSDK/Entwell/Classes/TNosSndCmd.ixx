module;
export module TNosSndCmd;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNosSndCmd : public TObject
	{
		char unknown[4];						// 0x04
		void* handler;							// 0x08
		struct TNTUnitManager* unitManager;     // 0x0C
		char* packet;							// 0x10
	};
	static_assert(sizeof(TNosSndCmd) == 0x14, "TNosSndCmd does not have a size of 0x14.");
#pragma pack(pop)
}