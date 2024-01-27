module;
#include <stdint.h>
export module TLBSGeometryCache;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	class TEWMultiFileStreamSimple;
	class TEWMultiFileStreamList;
	class TLBSTextureCache;
	template<typename T> class TList;
	class TLBSGeometryItem;

	export struct TLBSGeometryCache : public TObject
	{
		TEWMultiFileStreamSimple* unknown1;	// 0x04
		TEWMultiFileStreamList* unknown2;	// 0x08
		TLBSTextureCache* unknown3;			// 0x0C
		TList<TLBSGeometryItem*>* unknown4;	// 0x10
		int32_t nstgeId;					// 0x14 TMovePosiMarked is 0x4f000031 (1 325 400 113)
		TLBSGeometryItem* unknown6;			// 0x18
	};
	static_assert(sizeof(TLBSGeometryCache) == 0x1C, "TLBSGeometryCache does not have a size of 0x1C.");
#pragma pack(pop)
}