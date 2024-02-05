module;
#include <stdint.h>
export module TextPosition;
import Position;
import DelphiString;

namespace NosTaleSDK::Entwell::Properties::Graphical
{
#pragma pack(push, 1)
	export template<typename String>
	struct TextPosition
	{
		Logical::Position position;	// 0x000
		int16_t pxPerLine;			// 0x004
		int16_t lineSpacing;		// 0x006
		String* text;				// 0x008
		bool isVisible;				// 0x00C
		unsigned char padding[3];	// 0x00D
	};
	static_assert(sizeof(TextPosition<void*>) == 0x10, "TextPosition size isn't 0x10.");
	static_assert(sizeof(TextPosition<void*>) <= 0x10, "TextPosition size is upper than 0x10.");
	static_assert(sizeof(TextPosition<void*>) >= 0x10, "TextPosition size is lower than 0x10.");
#pragma pack(pop)
}