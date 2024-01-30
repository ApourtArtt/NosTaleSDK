module;
export module TPetSelectIcon;
import TNTTimeAniIcon;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TPetSelectIcon : public TNTTimeAniIcon
	{
		char unknown67[8]; // 0x11C
	};
	static_assert(sizeof(TPetSelectIcon) == 0x124, "TPetSelectIcon size isn't 0x124.");
	static_assert(sizeof(TPetSelectIcon) <= 0x124, "TPetSelectIcon size is upper than 0x124.");
	static_assert(sizeof(TPetSelectIcon) >= 0x124, "TPetSelectIcon size is lower than 0x124.");
#pragma pack(pop)
}