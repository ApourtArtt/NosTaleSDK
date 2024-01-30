module;
#include <stdint.h>
export module TLBSCanvasTexture;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSCanvasTexture : public TObject
	{
		uint32_t unknown;	// 0x004
		uint32_t unknown2;	// 0x008
		int unknown3;		// 0x00C
		void* unknown4;		// 0x010 IDirect3DTexture9
		uint8_t unknown5;	// 0x014
		char unknown6[3];	// 0x015
	};
	static_assert(sizeof(TLBSCanvasTexture) == 0x18, "TLBSCanvasTexture size isn't 0x18.");
	static_assert(sizeof(TLBSCanvasTexture) <= 0x18, "TLBSCanvasTexture size is upper than 0x18.");
	static_assert(sizeof(TLBSCanvasTexture) >= 0x18, "TLBSCanvasTexture size is lower than 0x18.");
#pragma pack(pop)
}