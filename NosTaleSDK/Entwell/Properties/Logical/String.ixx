module;
export module String;

namespace NosTaleSDK::Entwell::Properties::Logical
{
#pragma pack(push, 1)
	export struct String
	{
		size_t length;
		char* buffer;
	};
	static_assert(sizeof(String) == 0x8, "String does not have a size of 0x8.");
#pragma pack(pop)
}