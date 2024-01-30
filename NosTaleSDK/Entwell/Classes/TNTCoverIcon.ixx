module;
export module TNTCoverIcon;
import TNTIconWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTCoverIcon : public TNTIconWidget
	{
		char unknown48[4];		// 0x0CC
		uint32_t filter;		// 0x0D0
		bool isFilterEnabled;	// 0x0D4
		char unknown49[3];		// 0x0D5
	};
	static_assert(sizeof(TNTCoverIcon) == 0xD8, "TNTCoverIcon size isn't 0xD8.");
	static_assert(sizeof(TNTCoverIcon) <= 0xD8, "TNTCoverIcon size is upper than 0xD8.");
	static_assert(sizeof(TNTCoverIcon) >= 0xD8, "TNTCoverIcon size is lower than 0xD8.");
#pragma pack(pop)
}