module;
#include <stdint.h>
export module TLBSBkFxItem;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSBkFxItem : public TObject
	{
		uint32_t unknown1;		// 0x004 timestamp related
		uint32_t unknown2;		// 0x008 timestamp related
		uint8_t unknown3;		// 0x00C
		char unknown4[3];		// 0x00D
		float posX;				// 0x010
		float posZ;				// 0x014
		float posY;				// 0x018
		float unknown5;			// 0x01C
		float unknown6;			// 0x020
		int32_t timestamp;		// 0x024
		char unknown7[4];		// 0x028 -1 by default, updated on each tick
		int16_t unknown8;		// 0x02C
		char unknown9[2];		// 0x02E
	};
	static_assert(sizeof(TLBSBkFxItem) == 0x30, "TLBSBkFxItem size isn't 0x30.");
	static_assert(sizeof(TLBSBkFxItem) <= 0x30, "TLBSBkFxItem size is upper than 0x30.");
	static_assert(sizeof(TLBSBkFxItem) >= 0x30, "TLBSBkFxItem size is lower than 0x30.");
#pragma pack(pop)
}