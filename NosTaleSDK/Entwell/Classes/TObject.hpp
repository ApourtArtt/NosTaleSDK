#pragma once
#include <stdint.h>
#include <string_view>

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	// https://docwiki.embarcadero.com/Libraries/Sydney/en/System.TObject
	struct TObject
	{
		static constexpr std::string_view NAME = "TEWScrollBar";
		uintptr_t vTable; // 0x000
	};
	static_assert(sizeof(TObject) == 0x4);
	static_assert(sizeof(TObject) <= 0x4, "TObject's size is higher than 0x4.");
	static_assert(sizeof(TObject) >= 0x4, "TObject's size is lower than 0x4.");
#pragma pack(pop)
}