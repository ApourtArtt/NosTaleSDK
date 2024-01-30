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
	static_assert(sizeof(String) == 0x8, "String size isn't 0x8.");
	static_assert(sizeof(String) <= 0x8, "String size is upper than 0x8.");
	static_assert(sizeof(String) >= 0x8, "String size is lower than 0x8.");
#pragma pack(pop)
}