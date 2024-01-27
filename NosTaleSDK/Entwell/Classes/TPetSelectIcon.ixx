module;
export module TPetSelectIcon;
import TNTTimeAniIcon;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TPetSelectIcon : public TNTTimeAniIcon
	{
		char unknown21[0x14]; // 0x110
	};
	static_assert(sizeof(TPetSelectIcon) == 0x124, "TPetSelectIcon does not have a size of 0x124");
#pragma pack(pop)
}