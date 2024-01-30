module;
#include <stdint.h>
export module TMapObjFxItem;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TMapObjFxItem : public TObject
	{
		uint32_t unknown;	// 0x004
		char unknown2[4];	// 0x008
	};
	static_assert(sizeof(TMapObjFxItem) == 0xC, "TMapObjFxItem size isn't 0xC.");
	static_assert(sizeof(TMapObjFxItem) <= 0xC, "TMapObjFxItem size is upper than 0xC.");
	static_assert(sizeof(TMapObjFxItem) >= 0xC, "TMapObjFxItem size is lower than 0xC.");
#pragma pack(pop)
}