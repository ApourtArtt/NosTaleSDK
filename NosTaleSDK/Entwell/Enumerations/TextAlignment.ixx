module;
#include <stdint.h>
export module TextAlignment;

namespace NosTaleSDK::Entwell::Enumerations
{
	enum class TextAlignment : uint8_t
	{
		TopLeft = 0,
		CenteredLeft = 1,
		CenteredRight = 2,
		CenteredCentered = 3
	};
}