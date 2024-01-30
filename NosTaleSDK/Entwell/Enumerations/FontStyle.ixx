module;
#include <stdint.h>
export module FontStyle;

namespace NosTaleSDK::Entwell::Enumerations
{
#pragma pack(push, 1)
	export enum class FontStyle : uint8_t
	{
		Invisible = 0x00,
		Normal = 0x01,
		LittleSpacing = 0x02,
		Big = 0x03,
		Little = 0x04,
		Bold = 0x05
	};
#pragma pack(pop)
}