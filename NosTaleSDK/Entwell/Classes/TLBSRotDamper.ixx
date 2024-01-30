module;
export module TLBSRotDamper;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSRotDamper : public TObject
	{
		char unknown[84];	// 0x004
		float min;			// 0x058
		float max;			// 0x05C
		float def;			// 0x060
	};
	static_assert(sizeof(TLBSRotDamper) == 0x64, "TLBSMultiTextureList size isn't 0x64.");
	static_assert(sizeof(TLBSRotDamper) <= 0x64, "TLBSMultiTextureList size is upper than 0x64.");
	static_assert(sizeof(TLBSRotDamper) >= 0x64, "TLBSMultiTextureList size is lower than 0x64.");
#pragma pack(pop)
}