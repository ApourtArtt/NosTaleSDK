module;
#include <stdint.h>
export module TextShadowOrientation;

namespace NosTaleSDK::Entwell::Enumerations
{
#pragma pack(push, 1)
	enum class TextShadowOrientation : uint8_t
	{
		ShadowNone = 0,
		ShadowBottom = 1,
		ShadowBottomLeft = 2,
		ShadowBottomRight = 4,
		ShadowTop = 8,
		ShadowTopLeft = 16,
		ShadowTopRight = 32,
		ShadowLeft = 64,
		ShadowRight = 128,
		ShadowAll = 255,
	};
#pragma pack(pop)
}