module;
#include <stdint.h>
export module TextAlignment;

namespace NosTaleSDK::Entwell::Enumerations
{
#pragma pack(push, 1)
	enum class TextAlignment : uint8_t
	{
		TopLeft = 0,
		CenteredLeft = 1,
		CenteredRight = 2,
		CenteredCentered = 3
	};
#pragma pack(pop)
}