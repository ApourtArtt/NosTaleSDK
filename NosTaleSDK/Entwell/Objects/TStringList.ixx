module;
#include <stdint.h>
export module TStringList;
import TStrings;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TStringList : public TStrings
	{
		void* items;						// 0x10
		uint32_t length;                    // 0x14
		int32_t capacity;                   // 0x18
		bool isSorted;                      // 0x1C
		bool hasDuplicates;                 // 0x1D
		bool isCaseSensitive;               // 0x1E
		uint8_t pad_001F[1];                // 0x1F
		void* onChange;                     // 0x20
		uint8_t pad_0024[4];                // 0x24
		void* onChanging;                   // 0x28
		uint8_t pad_002C[4];                // 0x2C
	};
	static_assert(sizeof(TStringList) == 0x30, "TStringList does not have a size of 0x30.");
#pragma pack(pop)
}