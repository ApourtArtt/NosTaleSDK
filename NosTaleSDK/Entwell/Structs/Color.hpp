#pragma once
#include <stdint.h>

// http://docwiki.embarcadero.com/Libraries/Alexandria/en/Vcl.Controls.TControl.Color
namespace NosTaleSDK::Entwell::Structs
{
#pragma pack(push, 1)
	struct Color
	{
		uint8_t blue;
		uint8_t green;
		uint8_t red;
		uint8_t alpha;
	};
	static_assert(sizeof(Color) == 0x4, "Bgra size isn't 0x4.");
	static_assert(sizeof(Color) <= 0x4, "Bgra size is higher than 0x4.");
	static_assert(sizeof(Color) >= 0x4, "Bgra size is lower than 0x4.");
#pragma pack(pop)
}