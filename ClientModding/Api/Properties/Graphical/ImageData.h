#pragma once
#include "PictureView.h"
#pragma pack(push, 1)

/**
 * @brief Game widget image data representation.
 */
class ImageData
{
public:
	ImageData(int32_t ImageName, int16_t ImageWidth, int16_t ImageHeight, PictureDisplayer* PictureDisplayer)
		: nbPictureViews(PictureDisplayer ? PictureDisplayer->nbPictureViews : 0)
		, imageName(ImageName)
		, imageWidth(ImageWidth)
		, imageHeight(ImageHeight)
		, pictureViews(PictureDisplayer ? PictureDisplayer->pictureViews : 0)
	{}

	ImageData()
		: ImageData(0, 0, 0, nullptr)
	{}

private:
	int16_t nbPictureViews;		// 0x00
	int32_t imageName;			// 0x02
	int16_t imageWidth;			// 0x04
	int16_t imageHeight;		// 0x06
	PictureView* pictureViews;	// 0x0A
};

#pragma pack(pop)