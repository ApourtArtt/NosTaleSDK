module;
#include <stdint.h>
export module TLBSTextRender;
import TLBSCanvasTextureEX;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSTextRender : public TLBSCanvasTextureEX
	{
		uint32_t unknown13; // 0x028
	};
	static_assert(sizeof(TLBSTextRender) == 0x2C, "TLBSTextRender size isn't 0x2C.");
	static_assert(sizeof(TLBSTextRender) <= 0x2C, "TLBSTextRender size is upper than 0x2C.");
	static_assert(sizeof(TLBSTextRender) >= 0x2C, "TLBSTextRender size is lower than 0x2C.");
#pragma pack(pop)
}