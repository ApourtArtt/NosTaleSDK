module;
#include <stdint.h>
export module TComponent;
import TPersistent;
template<typename> struct TList;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TComponent : public TPersistent
	{
		TComponent* owner;						// 0x004
		uint32_t name;							// 0x008
		int tag;								// 0x00C
		TList<TComponent*>* components;			// 0x010
		TList<void*>* freeNotifies;				// 0x014
		long designInfo;						// 0x018
		uint32_t state;							// 0x01C
		void* vclComObject;						// 0x020
		uint32_t style;							// 0x024
		char unknown[8];						// 0x028
	};
	static_assert(sizeof(TComponent) == 0x30, "TComponent size isn't 0x30.");
	static_assert(sizeof(TComponent) <= 0x30, "TComponent size is upper than 0x30.");
	static_assert(sizeof(TComponent) >= 0x30, "TComponent size is lower than 0x30.");
#pragma pack(pop)
}