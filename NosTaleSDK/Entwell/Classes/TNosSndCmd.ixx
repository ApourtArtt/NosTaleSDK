module;
#include <stdint.h>
export module TNosSndCmd;
import TObject;
import Callback;
import String;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNosSndCmd : public TObject
	{
		uint32_t unknown;						// 0x004
		Properties::Logical::Callback callback;	// 0x008
		Properties::Logical::String* packet;	// 0x010
	};
	static_assert(sizeof(TNosSndCmd) == 0x14, "TNosSndCmd size isn't 0x14.");
	static_assert(sizeof(TNosSndCmd) <= 0x14, "TNosSndCmd size is upper than 0x14.");
	static_assert(sizeof(TNosSndCmd) >= 0x14, "TNosSndCmd size is lower than 0x14.");
#pragma pack(pop)
}