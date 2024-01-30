module;
export module TStrings;
import TPersistent;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TStrings : public TPersistent
	{
		char defined;				// 0x004
		char delimiter;				// 0x005
		char quoteChar;				// 0x006
		char nameValueSeparator;	// 0x007
		int updateCount;			// 0x008
		void* adapter;				// 0x00C
	};
	static_assert(sizeof(TStrings) == 0x10, "TStrings size isn't 0x10.");
	static_assert(sizeof(TStrings) <= 0x10, "TStrings size is upper than 0x10.");
	static_assert(sizeof(TStrings) >= 0x10, "TStrings size is lower than 0x10.");
#pragma pack(pop)
}