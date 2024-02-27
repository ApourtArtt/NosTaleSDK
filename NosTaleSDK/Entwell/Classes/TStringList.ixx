module;
#include <stdint.h>
#include <Windows.h>
export module TStringList;
import TStrings;
import Callback;
import DelphiArray;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TStringList : public TStrings
	{
		Properties::Logical::DelphiArrayRefCounted<char*>* items;// 0x010
		uint32_t length;									// 0x014
		int32_t capacity;									// 0x018
		bool isSorted;										// 0x01C
		bool hasDuplicates;									// 0x01D
		bool isCaseSensitive;								// 0x01E
		char unknown;										// 0x01F
		Properties::Logical::Callback onChange;				// 0x020
		Properties::Logical::Callback onChanging;			// 0x028
	};
	static_assert(sizeof(TStringList) == 0x30, "TStringList size isn't 0x30.");
	static_assert(sizeof(TStringList) <= 0x30, "TStringList size is upper than 0x30.");
	static_assert(sizeof(TStringList) >= 0x30, "TStringList size is lower than 0x30.");
#pragma pack(pop)
}