module;
export module TLBSCamera;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSCamera : public TObject
	{
		char unknown[736];							// 0x004
		struct TLBSPosDamper* posDamper;			// 0x2E4
		struct TLBSRotDamper* horizontalRotDamper;	// 0x2E8
		TLBSRotDamper* verticalRotDamper;			// 0x2EC
		TLBSRotDamper* zoomRotDamper;				// 0x2F0
		char unknown2[4];							// 0x2F4
	};
	static_assert(sizeof(TLBSCamera) == 0x2F8, "TLBSCamera size isn't 0x2F8.");
	static_assert(sizeof(TLBSCamera) <= 0x2F8, "TLBSCamera size is upper than 0x2F8.");
	static_assert(sizeof(TLBSCamera) >= 0x2F8, "TLBSCamera size is lower than 0x2F8.");
#pragma pack(pop)
}