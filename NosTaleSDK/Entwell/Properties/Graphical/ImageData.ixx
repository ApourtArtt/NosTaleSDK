module;
#include <stdint.h>
export module ImageData;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct ImageData
	{
		int16_t nbPictureViews;				// 0x000
		int32_t imageName;					// 0x002
		int16_t imageWidth;					// 0x004
		int16_t imageHeight;				// 0x006
		struct PictureView* pictureViews;	// 0x00A
	};
	static_assert(sizeof(ImageData) == 0xE, "ImageData size isn't 0xE.");
	static_assert(sizeof(ImageData) <= 0xE, "ImageData size is upper than 0xE.");
	static_assert(sizeof(ImageData) >= 0xE, "ImageData size is lower than 0xE.");
#pragma pack(pop)
}