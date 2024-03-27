#pragma onc
#include "BoundsRect.hpp"

namespace NosTaleSDK::Entwell::Structs
{
#pragma pack(push, 1)
	struct PictuveView
	{
		BoundsRect pictureViews[30];	// 0x000
		int16_t nbPictureViews;			// 0x0F0
	};
	static_assert(sizeof(PictuveView) == 0xF2, "PictuveView size isn't 0xF2.");
	static_assert(sizeof(PictuveView) <= 0xF2, "PictuveView size is higher than 0xF2.");
	static_assert(sizeof(PictuveView) >= 0xF2, "PictuveView size is lower than 0xF2.");
#pragma pack(pop)
}