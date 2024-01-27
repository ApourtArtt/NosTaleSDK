module;
#include <stdint.h>
export module ImageData;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct ImageData
	{
		int16_t nbPictureViews;		// 0x00
		int32_t imageName;			// 0x02
		int16_t imageWidth;			// 0x04
		int16_t imageHeight;		// 0x06
		struct PictureView* pictureViews;	// 0x0A
	};
	static_assert(sizeof(ImageData) == 0xE, "ImageData does not have a size of 0xE.");
#pragma pack(pop)
}