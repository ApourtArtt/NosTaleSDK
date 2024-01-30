module;
#include <stdint.h>
export module TLBSGeometryCache;
import TObject;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSGeometryCache : public TObject
	{
		struct TEWMultiFileStreamSimple* unknown;			// 0x004
		struct TEWMultiFileStreamList* unknown2;			// 0x008
		struct TLBSTextureCache* unknown3;					// 0x00C
		struct TList<struct TLBSGeometryItem*>* unknown4;	// 0x010
		int32_t nstgeId;									// 0x014
		struct TLBSGeometryItem* unknown5;					// 0x018
	};
	static_assert(sizeof(TLBSGeometryCache) == 0x1C, "TLBSGeometryCache size isn't 0x1C.");
	static_assert(sizeof(TLBSGeometryCache) <= 0x1C, "TLBSGeometryCache size is upper than 0x1C.");
	static_assert(sizeof(TLBSGeometryCache) >= 0x1C, "TLBSGeometryCache size is lower than 0x1C.");
#pragma pack(pop)
}