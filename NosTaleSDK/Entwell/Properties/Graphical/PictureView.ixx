module;
#include <stdint.h>
export module PictureView;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct PictureView
	{
		int16_t topLeftX;	// 0x000
		int16_t topLeftY;	// 0x002
		int16_t width;		// 0x004
		int16_t height;		// 0x006
	};
	static_assert(sizeof(PictureView) == 0x8, "PictureView size isn't 0x8.");
	static_assert(sizeof(PictureView) <= 0x8, "PictureView size is upper than 0x8.");
	static_assert(sizeof(PictureView) >= 0x8, "PictureView size is lower than 0x8.");
#pragma pack(pop)
}