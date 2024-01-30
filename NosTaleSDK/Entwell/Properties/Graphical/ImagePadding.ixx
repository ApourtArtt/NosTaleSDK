module;
#include <stdint.h>
export module ImagePadding;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct ImagePadding
	{
		int16_t widthMiddle;	// 0x000
		int16_t heightMiddle;	// 0x002
		int16_t posRight;		// 0x004
		int16_t posBot;			// 0x006
		int16_t widthLeft;		// 0x008
		int16_t heightTop;		// 0x00A
		int16_t widthRight;		// 0x00C
		int16_t heightBot;		// 0x00E
	};
	static_assert(sizeof(ImagePadding) == 0x10, "ImagePadding size isn't 0x10.");
	static_assert(sizeof(ImagePadding) <= 0x10, "ImagePadding size is upper than 0x10.");
	static_assert(sizeof(ImagePadding) >= 0x10, "ImagePadding size is lower than 0x10.");
#pragma pack(pop)
}