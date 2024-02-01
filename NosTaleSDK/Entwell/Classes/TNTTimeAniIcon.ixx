module;
#include <stdint.h>
export module TNTTimeAniIcon;
import TNTIconWidget;
import Bgra;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTTimeAniIcon : public TNTIconWidget
	{
		char unknown48[4];								// 0x0CC
		float unknown49;								// 0x0D0
		uint32_t unknown50;								// 0x0D4
		uint32_t unknown51;								// 0x0D8
		float unknown52;								// 0x0DC
		float unknown53;								// 0x0E0
		uint32_t unknown54;								// 0x0E4
		uint32_t unknown55;								// 0x0E8
		float unknown56;								// 0x0EC
		float unknown57;								// 0x0F0
		uint32_t unknown58;								// 0x0F4
		float unknown59;								// 0x0F8
		Properties::Graphical::Bgra cdProgressColor;	// 0x0FC
		struct TEWLabel* unknown60;						// 0x100
		int32_t cdCurrentTime;							// 0x104
		int32_t cdTime;									// 0x108
		int32_t unknown61;								// 0x10C
		uint32_t unknown62;								// 0x110
		uint8_t isTransparent;							// 0x114
		uint8_t unknown63;								// 0x115
		uint8_t isOnCd;									// 0x116
		uint8_t unknown64;								// 0x117
		uint8_t unknown65;								// 0x118
		char unknown66[3];								// 0x119
	};
	static_assert(sizeof(TNTTimeAniIcon) == 0x11C, "TNTTimeAniIcon size isn't 0x11C.");
	static_assert(sizeof(TNTTimeAniIcon) <= 0x11C, "TNTTimeAniIcon size is upper than 0x11C.");
	static_assert(sizeof(TNTTimeAniIcon) >= 0x11C, "TNTTimeAniIcon size is lower than 0x11C.");
#pragma pack(pop)
}