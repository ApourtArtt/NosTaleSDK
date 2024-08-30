#pragma once
#include <vector>
#include "BoundsRect.hpp"

namespace NosTaleSDK::Entwell::Structs
{
#pragma pack(push, 1)
	class PictureView
	{
	public:
		PictureView(int16_t TopLeftX = 0, int16_t TopLeftY = 0, int16_t Width = 0, int16_t Height = 0)
			: topLeftX(TopLeftX)
			, topLeftY(TopLeftY)
			, width(Width)
			, height(Height)
		{}

	private:
		int16_t topLeftX;	// 0x00
		int16_t topLeftY;	// 0x02
		int16_t width;		// 0x04
		int16_t height;		// 0x06
	};
	static_assert(sizeof(PictureView) == 0x8, "PictureView's size isn't 0x8.");
	static_assert(sizeof(PictureView) <= 0x8, "PictureView's size is higher than 0x8.");
	static_assert(sizeof(PictureView) >= 0x8, "PictureView's size is lower than 0x8.");

	// Rework this class. Should be handled similarly as Delphi strings (dynamic memory)
	class PictureViewer
	{
	public:
		PictureViewer(std::vector<PictureView> PictureViews = {});

	private:
		PictureView pictureViews[30];	// 0x000
		int16_t nbPictureViews;			// 0x0F0
	};
	static_assert(sizeof(PictureViewer) == 0xF2, "PictureViewer's size is not 0xF2.");
	static_assert(sizeof(PictureViewer) <= 0xF2, "PictureViewer's size is higher than 0xF2.");
	static_assert(sizeof(PictureViewer) >= 0xF2, "PictureViewer's size is lower than 0xF2.");
#pragma pack(pop)
}