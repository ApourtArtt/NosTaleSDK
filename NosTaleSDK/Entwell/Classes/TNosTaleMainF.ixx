module;
#include <stdint.h>
export module TNosTaleMainF;
import TForm;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNosTaleMainF : public TForm
	{
		struct TNosTaleGame* game;	// 0x2F8
		uint16_t unknown9;			// 0x2FC
		uint8_t unknown10;			// 0x2FE
		char unknown11;				// 0x2FF
		struct TCkThread* thread;	// 0x300
	};
	static_assert(sizeof(TNosTaleMainF) == 0x304, "TNosTaleMainF size isn't 0x304.");
	static_assert(sizeof(TNosTaleMainF) <= 0x304, "TNosTaleMainF size is upper than 0x304.");
	static_assert(sizeof(TNosTaleMainF) >= 0x304, "TNosTaleMainF size is lower than 0x304.");
#pragma pack(pop)
}