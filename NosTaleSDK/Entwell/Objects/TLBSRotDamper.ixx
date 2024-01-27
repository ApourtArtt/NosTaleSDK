module;
#include <stdint.h>
export module TLBSRotDamper;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSRotDamper : public TObject
	{
		char pad_0004[84]; //0x04
		float min; //0x58
		float max; //0x5C
		float def; //0x60
	};
	static_assert(sizeof(TLBSRotDamper) == 0x64, "TLBSRotDamper does not have a size of 0x64");
#pragma pack(pop)
}