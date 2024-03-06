module;
#include <stdint.h>
export module TNosRevCmd;
import TObject;
import Callback;
import DelphiArray;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNosRevCmd : public TObject
	{
		uint32_t unknown;								// 0x004
		Properties::Logical::Callback callback;			// 0x008
		Properties::Logical::DelphiArray<char>* packet;	// 0x010
	};
	static_assert(sizeof(TNosRevCmd) == 0x14, "TNosRevCmd size isn't 0x14.");
	static_assert(sizeof(TNosRevCmd) <= 0x14, "TNosRevCmd size is upper than 0x14.");
	static_assert(sizeof(TNosRevCmd) >= 0x14, "TNosRevCmd size is lower than 0x14.");
#pragma pack(pop)
}