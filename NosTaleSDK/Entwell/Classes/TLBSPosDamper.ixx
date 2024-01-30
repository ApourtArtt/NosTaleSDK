module;
export module TLBSPosDamper;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	struct TLBSPosDamper : public TObject
	{
		char unknown[116]; // 0x004
	};
	static_assert(sizeof(TLBSPosDamper) == 0x78, "TLBSPosDamper size isn't 0x78.");
	static_assert(sizeof(TLBSPosDamper) <= 0x78, "TLBSPosDamper size is upper than 0x78.");
	static_assert(sizeof(TLBSPosDamper) >= 0x78, "TLBSPosDamper size is lower than 0x78.");
#pragma pack(pop)
}