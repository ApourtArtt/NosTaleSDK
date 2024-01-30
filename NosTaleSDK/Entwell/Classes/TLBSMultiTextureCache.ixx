module;
#include <stdint.h>
export module TLBSMultiTextureCache;
import TObject;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSMultiTextureCache : public TObject
	{
		char unknown[4];						// 0x004
		char unknown2[4];						// 0x008
		struct TLBSMultiTextureList* unknown3;	// 0x00C
		struct TLBSMultiTextureList* unknown4;	// 0x010
		struct TList<void*>* unknown5;			// 0x014
	};
	static_assert(sizeof(TLBSMultiTextureCache) == 0x18, "TLBSMultiTextureCache size isn't 0x18.");
	static_assert(sizeof(TLBSMultiTextureCache) <= 0x18, "TLBSMultiTextureCache size is upper than 0x18.");
	static_assert(sizeof(TLBSMultiTextureCache) >= 0x18, "TLBSMultiTextureCache size is lower than 0x18.");
#pragma pack(pop)
}