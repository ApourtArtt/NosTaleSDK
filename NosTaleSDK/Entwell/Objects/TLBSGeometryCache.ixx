module;
#include <stdint.h>
export module TLBSGeometryCache;
import TObject;
import TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TLBSGeometryCache : public TObject
	{
		struct TEWMultiFileStreamSimple* unknown1;	// 0x04
		struct TEWMultiFileStreamList* unknown2;	// 0x08
		struct TLBSTextureCache* unknown3;			// 0x0C
		struct TList<struct TLBSGeometryItem*>* unknown4;	// 0x10
		int32_t nstgeId;					// 0x14 TMovePosiMarked is 0x4f000031 (1 325 400 113)
		struct TLBSGeometryItem* unknown6;			// 0x18
	};
	static_assert(sizeof(TLBSGeometryCache) == 0x1C, "TLBSGeometryCache does not have a size of 0x1C.");
#pragma pack(pop)
}