module;
#include <stdint.h>
export module TextAlignment;

namespace NosTaleSDK::Entwell::Enumerations
{
	export enum class TextAlignment : uint8_t
	{
		TOP_LEFT = 0,
		CENTERED_LEFT = 1,
		CENTERED_RIGHT = 2,
		CENTERED_CENTERED = 3
	};
}