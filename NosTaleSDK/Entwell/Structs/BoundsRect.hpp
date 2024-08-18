#pragma once
#include <stdint.h>

// http://docwiki.embarcadero.com/Libraries/Alexandria/en/Vcl.Controls.TControl.BoundsRect
namespace NosTaleSDK::Entwell::Structs
{
#pragma pack(push, 1)
	struct BoundsRect
	{
		int16_t topLeftX;	// 0x000
		int16_t topLeftY;	// 0x002
		int16_t botRightX;  // 0x004
		int16_t botRightY;	// 0x006
	};
	static_assert(sizeof(BoundsRect) == 0x8, "BoundsRect size isn't 0x8.");
	static_assert(sizeof(BoundsRect) <= 0x8, "BoundsRect size is higher than 0x8.");
	static_assert(sizeof(BoundsRect) >= 0x8, "BoundsRect size is lower than 0x8.");
#pragma pack(pop)
}