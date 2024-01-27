module;
export module WideString;

namespace NosTaleSDK::Entwell::Properties::Logical
{
#pragma pack(push, 1)
	export struct WideString
	{
		wchar_t* buffer;
	};
	static_assert(sizeof(WideString) == 0x4, "WideString does not have a size of 0x4.");
#pragma pack(pop)
}