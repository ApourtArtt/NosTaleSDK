module;
#include <stdint.h>
export module TLBSBkFxItem;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSBkFxItem : public TObject
	{
		int32_t unknown1;		// 0x04 Related to timestamp, added to unknown2
		int32_t unknown2;		// 0x08 Related to timestamp
		int32_t unknown6;		// 0x0C
		int32_t posX;			// 0x10 This is not map on grid but a huge value
		int32_t posZ;			// 0x14 Same
		int32_t posY;			// 0x18 Same
		float unknown7;			// 0x1C Does not seem to be a translation, but is used altogether with posX/Y/Z (logically, but didn't find any diff graphically)
		float unknown5;			// 0x20
		int32_t timestamp;		// 0x24
		char unknown8[4];		// 0x28 -1 by default, if moved to 0, it gets deleted on next tick
		int16_t unknown3;		// 0x2C
		char unknown4[2];		// 0x2E
	};
	static_assert(sizeof(TLBSBkFxItem) == 0x30, "TLBSBkFxItem does not have a size of 0x30.");
#pragma pack(pop)
}