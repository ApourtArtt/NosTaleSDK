module;
export module WideString;

namespace NosTaleSDK::Entwell::Properties::Logical
{
#pragma pack(push, 1)
	export struct WideString
	{
		wchar_t* buffer;
	};
	static_assert(sizeof(WideString) == 0x4, "WideString size isn't 0x4.");
	static_assert(sizeof(WideString) <= 0x4, "WideString size is upper than 0x4.");
	static_assert(sizeof(WideString) >= 0x4, "WideString size is lower than 0x4.");
#pragma pack(pop)
}