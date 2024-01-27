module;
#include <stdint.h>
export module PictureView;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct PictureView
	{
		int16_t topLeftX;	// 0x00
		int16_t topLeftY;	// 0x02
		int16_t width;		// 0x04
		int16_t length;		// 0x06
	};
	static_assert(sizeof(PictureView) == 0x8, "PictureView does not have a size of 0x8.");
#pragma pack(pop)
}