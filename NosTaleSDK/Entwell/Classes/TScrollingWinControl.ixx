module;
#include <stdint.h>
export module TScrollingWinControl;
import TWinControl;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TScrollingWinControl : public TWinControl
	{
		char unknown7[0x18]; // 0x204
	};
	static_assert(sizeof(TScrollingWinControl) == 0x21C, "TScrollingWinControl size isn't 0x21C.");
	static_assert(sizeof(TScrollingWinControl) <= 0x21C, "TScrollingWinControl size is upper than 0x21C.");
	static_assert(sizeof(TScrollingWinControl) >= 0x21C, "TScrollingWinControl size is lower than 0x21C.");
#pragma pack(pop)
}