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
		char unknown[4];		// 0x004
		uint32_t unknown2;		// 0x008
		uint32_t unknown3;		// 0x00C
		char unknown4[4];		// 0x010
		int8_t unknown5;		// 0x014
		char unknown6[3];		// 0x015
		uint32_t unknown7;		// 0x018
		int unknown8;			// 0x01C
	};
	static_assert(sizeof(TBaseList<void*>) == 0x20, "TBaseList size isn't 0x20.");
	static_assert(sizeof(TBaseList<void*>) <= 0x20, "TBaseList size is upper than 0x20.");
	static_assert(sizeof(TBaseList<void*>) >= 0x20, "TBaseList size is lower than 0x20.");
#pragma pack(pop)
}