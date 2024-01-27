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
	static_assert(sizeof(PictureDisplay) == 0xF2, "PictureDisplay does not have a size of 0xF2.");
#pragma pack(pop)
}