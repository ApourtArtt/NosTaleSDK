module;
#include <stdint.h>
export module ImagePadding;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct ImagePadding
	{
		int16_t widthMiddle;	// 0x00
		int16_t heightMiddle;	// 0x02

		int16_t posRight;		// 0x04
		int16_t posBot;			// 0x06

		int16_t widthLeft;		// 0x08
		int16_t heightTop;		// 0x0A

		int16_t widthRight;		// 0x0C
		int16_t heightBot;		// 0x0E
	};
	static_assert(sizeof(ImagePadding) == 0x10, "ImagePadding does not have a size of 0x10.");
#pragma pack(pop)
}