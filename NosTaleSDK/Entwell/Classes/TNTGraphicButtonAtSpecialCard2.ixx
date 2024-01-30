module;
#include <stdint.h>
export module TNTGraphicButtonAtSpecialCard2;
import TEWGraphicButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTGraphicButtonAtSpecialCard2 : public TEWGraphicButtonWidget
	{
		char unknown37[4];	// 0x0DC
	};
	static_assert(sizeof(TNTGraphicButtonAtSpecialCard2) == 0xE0, "TNTGraphicButtonAtSpecialCard2 size isn't 0xE0.");
	static_assert(sizeof(TNTGraphicButtonAtSpecialCard2) <= 0xE0, "TNTGraphicButtonAtSpecialCard2 size is upper than 0xE0.");
	static_assert(sizeof(TNTGraphicButtonAtSpecialCard2) >= 0xE0, "TNTGraphicButtonAtSpecialCard2 size is lower than 0xE0.");
#pragma pack(pop)
}