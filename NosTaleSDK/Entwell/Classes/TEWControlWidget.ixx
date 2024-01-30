module;
#include <stdint.h>
export module TEWControlWidget;
import TLBSWidget;
import Bgra;
import ImageData;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TEWControlWidget : public TLBSWidget
	{
		char unknown5[4];														// 0x024
		uint32_t unknown6;														// 0x028
		uint32_t unknown7;														// 0x02C
		uint32_t unknown8;														// 0x030
		uint32_t unknown9;														// 0x034
		uint32_t unknown10;														// 0x038
		uint32_t unknown11;														// 0x03C
		uint8_t unknown12;														// 0x040
		struct NosTaleSDK::Entwell::Properties::Graphical::Bgra color;			// 0x041
		uint32_t unknown13;														// 0x045
		char unknown14[3];														// 0x049
		bool unknown15;															// 0x04C
		int8_t currentPictureViewIndex;											// 0x04D
		int8_t unknown16;														// 0x04E
		struct NosTaleSDK::Entwell::Properties::Graphical::ImageData imageData;	// 0x04F
		char unknown17;															// 0x05D
		int16_t unknown18;														// 0x05E
		int32_t functionArgument;												// 0x060
		int32_t unknown19;														// 0x064
	};
	static_assert(sizeof(TEWControlWidget) == 0x68, "TEWControlWidget size isn't 0x68.");
	static_assert(sizeof(TEWControlWidget) <= 0x68, "TEWControlWidget size is upper than 0x68.");
	static_assert(sizeof(TEWControlWidget) >= 0x68, "TEWControlWidget size is lower than 0x68.");
#pragma pack(pop)
}