module;
export module TNTCoverIcon;
import TNTIconWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCoverIcon : public TNTIconWidget
	{
		char unknown21[4];	// 0xCC
		char filter[4];		// 0xD0
		bool useFilter;		// 0xD4
		char unknown22[3];	// 0xD5
	};
	static_assert(sizeof(TNTCoverIcon) == 0xD8, "TNTCoverIcon does not have a size of 0xD8.");
#pragma pack(pop)
}