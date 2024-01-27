module;
#include <stdint.h>
export module TNTIconViewer;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIconViewer : public TEWControlWidgetEX
	{
		char unknown13;				// 0x68 probably same as imageHandlingType from TNTIconWidget
		char unknown14;				// 0x69 related to 0x4D
		char unknown15;				// 0x6A related to 0x44
		char unknown16;				// 0x6B probably padding
		float unknown17;			// 0x6C no W/R found
		char unknown18[4];			// 0x70
		int16_t itemVnum;			// 0x74
		char unknown19[2];			// 0x76 padding? FF FF
		char unknown20[4];			// 0x78 FF FF FF FF
		char unknown21[4];			// 0x7C FF FF FF FF
		char unknown22[4];			// 0x80 FF FF FF FF
		char unknwon23[4];			// 0x84 FF 00 00 00
		char unknown24[4];			// 0x88 80 3E 00 00 (maybe 0x83 float)
		char unknown25[4];			// 0x8C 00 00 00 00
		char unknown26[30];			// 0x90 used when 0x68 is not item
		short colorStyle;			// 0xAE if == -2 then color is greyed out, if -1 then widget color is applied, if >= 0 && <= 15 then special color is applied (enum)
	};
	static_assert(sizeof(TNTIconViewer) == 0xB0, "TNTIconViewer does not have a size of 0xB0.");
#pragma pack(pop)
}