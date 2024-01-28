module;
#include <stdint.h>
export module TBaseList;
import TObject;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export template<typename T>
	struct TBaseList : public TObject
	{
		char unknown[4];	// 0x04
		char unknown2[4];	// 0x08
		char unknown3[4];	// 0x0C
		char unknown4[4];	// 0x10
		int8_t unknown5;	// 0x14
		char unknown6[3];	// 0x15
		char unknown7[4];	// 0x18
		int unknown8;		// 0x1C
	};
	static_assert(sizeof(TBaseList<void*>) == 0x20, "TBaseList does not have a size of 0x20.");
#pragma pack(pop)
}