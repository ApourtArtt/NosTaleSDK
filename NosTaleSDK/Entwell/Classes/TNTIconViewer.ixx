module;
#include <stdint.h>
export module TNTIconViewer;
import TEWControlWidgetEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTIconViewer : public TEWControlWidgetEX
	{
		uint8_t unknown20;			// 0x068
		uint8_t unknown21;			// 0x069
		uint8_t unknown22;			// 0x06A
		char unknown23;				// 0x06B
		float unknown24;			// 0x06C
		uint8_t unknown25;			// 0x070
		uint8_t unknown26;			// 0x071
		uint8_t unknown27;			// 0x072
		uint8_t unknown28;			// 0x073
		int16_t itemVnum;			// 0x074
		uint16_t unknown29;			// 0x076
		char unknown30[42];			// 0x078
		uint8_t unknown31;			// 0x0A2
		char unknown32[7];			// 0x0A3
		uint16_t unknown33;			// 0x0AA
		uint8_t unknown34;			// 0x0AC
		char unknown35;				// 0x0AD
		uint16_t colorStyle;		// 0x0AE if == -2 then color is greyed out, if -1 then widget color is applied, if >= 0 && <= 15 then special color is applied (enum)
	};
	static_assert(sizeof(TNTIconViewer) == 0xB0, "TNTIconViewer size isn't 0xB0.");
	static_assert(sizeof(TNTIconViewer) <= 0xB0, "TNTIconViewer size is upper than 0xB0.");
	static_assert(sizeof(TNTIconViewer) >= 0xB0, "TNTIconViewer size is lower than 0xB0.");
#pragma pack(pop)
}