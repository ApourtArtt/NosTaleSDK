module;
#include <stdint.h>
export module PictureDisplay;
import PictureView;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct PictureDisplay
	{
		PictureView pictureViews[30];	// 0x000
		int16_t nbPictureViews;			// 0x0F0
	};
	static_assert(sizeof(PictureDisplay) == 0xF2, "PictureDisplay size isn't 0xF2.");
	static_assert(sizeof(PictureDisplay) <= 0xF2, "PictureDisplay size is upper than 0xF2.");
	static_assert(sizeof(PictureDisplay) >= 0xF2, "PictureDisplay size is lower than 0xF2.");
#pragma pack(pop)
}