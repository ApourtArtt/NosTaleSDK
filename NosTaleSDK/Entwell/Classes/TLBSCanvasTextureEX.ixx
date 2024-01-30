module;
#include <stdint.h>
export module TLBSCanvasTextureEX;
import TLBSCanvasTexture;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSCanvasTextureEX : public TLBSCanvasTexture
	{
		uint16_t unknown7;	// 0x018
		uint16_t unknown8;	// 0x01A
		float unknown9;		// 0x01C
		float unknown10;	// 0x020
		uint8_t unknown11;	// 0x024
		char unknown12[3];	// 0x025
	};
	static_assert(sizeof(TLBSCanvasTextureEX) == 0x28, "TLBSCanvasTextureEX size isn't 0x28.");
	static_assert(sizeof(TLBSCanvasTextureEX) <= 0x28, "TLBSCanvasTextureEX size is upper than 0x28.");
	static_assert(sizeof(TLBSCanvasTextureEX) >= 0x28, "TLBSCanvasTextureEX size is lower than 0x28.");
#pragma pack(pop)
}