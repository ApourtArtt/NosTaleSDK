#pragma once
#include <stdint.h>
#include <vector>
#pragma pack(push, 1)

/**
 * @brief Game picture view representation.
 */
class PictureView
{
public:
	PictureView()
		: topLeftX(0)
		, topLeftY(0)
		, width(0)
		, length(0)
	{}

	PictureView(int16_t TopLeftX, int16_t TopLeftY, int16_t Width, int16_t Length)
		: topLeftX(TopLeftX)
		, topLeftY(TopLeftY)
		, width(Width)
		, length(Length)
	{}

	int16_t topLeftX;	// 0x00
	int16_t topLeftY;	// 0x02
	int16_t width;		// 0x04
	int16_t length;		// 0x06
};

// Note : should be used as a pointer, else NosTale will detect an image,
// even if we don't want it.
class PictureDisplayer
{
public:
	PictureDisplayer()
		: pictureViews()
		, nbPictureViews(0)
	{}

	PictureDisplayer(std::vector<PictureView> PictureViews)
		: PictureDisplayer()
	{
		for (size_t i = 0; i < PictureViews.size() && i < 30; i++)
			pictureViews[i] = PictureViews[i];
		nbPictureViews = static_cast<int16_t>(PictureViews.size());
	}

	PictureView pictureViews[30];
	int16_t nbPictureViews;
};

#pragma pack(pop)