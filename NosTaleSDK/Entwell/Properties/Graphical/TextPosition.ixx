module;
#include <stdint.h>
export module TextPostion;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export struct TextPostion
	{
		int16_t x;					// 0x00
		int16_t y;					// 0x02
		int16_t pxPerLine;			// 0x04
		int16_t lineSpacing;		// 0x06
		wchar_t* text;				// 0x08
		bool isVisible;				// 0x0C
		unsigned char padding[3];	// 0x0D
	};
	static_assert(sizeof(TextPostion) == 0x10, "TextPostion does not have a size of 0x10.");
#pragma pack(pop)
}