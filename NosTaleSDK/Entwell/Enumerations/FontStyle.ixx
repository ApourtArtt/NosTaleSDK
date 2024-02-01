module;
#include <stdint.h>
export module FontStyle;

namespace NosTaleSDK::Entwell::Enumerations
{
#pragma pack(push, 1)
	export enum class FontStyle : uint8_t
	{
		INVISIBLE = 0x00,
		NORMAL = 0x01,
		LITTLE_SPACING = 0x02,
		BIG = 0x03,
		LITTLE = 0x04,
		BOLD = 0x05
	};
#pragma pack(pop)
}