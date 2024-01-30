module;
#include <stdint.h>
export module PictureDisplay;
import PictureView;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct PictureDisplay
	{
		struct PictureView pictureViews[30];
		int16_t nbPictureViews;
	};
	static_assert(sizeof(PictureDisplay) == 0xF2, "PictureDisplay size isn't 0xF2.");
	static_assert(sizeof(PictureDisplay) <= 0xF2, "PictureDisplay size is upper than 0xF2.");
	static_assert(sizeof(PictureDisplay) >= 0xF2, "PictureDisplay size is lower than 0xF2.");
#pragma pack(pop)
}