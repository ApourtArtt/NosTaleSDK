module;
#include <stdint.h>
export module TextShadowOrientation;

namespace NosTaleSDK::Entwell::Enumerations
{
#pragma pack(push, 1)
	export enum class TextShadowOrientation : uint8_t
	{
		SHADOW_NONE = 0,
		SHADOW_BOTTOM = 1,
		SHADOW_BOTTOM_LEFT = 2,
		SHADOW_BOTTOM_RIGHT = 4,
		SHADOW_TOP = 8,
		SHADOW_TOP_LEFT = 16,
		SHADOW_TOP_RIGHT = 32,
		SHADOW_LEFT = 64,
		SHADOW_RIGHT = 128,
		SHADOW_ALL = 255,
	};
#pragma pack(pop)

	inline TextShadowOrientation operator|(TextShadowOrientation A, TextShadowOrientation B)
	{
		return static_cast<TextShadowOrientation>(static_cast<uint8_t>(A) | static_cast<uint8_t>(B));
	}

	inline TextShadowOrientation operator&(TextShadowOrientation A, TextShadowOrientation B)
	{
		return static_cast<TextShadowOrientation>(static_cast<uint8_t>(A) & static_cast<uint8_t>(B));
	}
}