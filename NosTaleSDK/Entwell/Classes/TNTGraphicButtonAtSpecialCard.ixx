module;
#include <stdint.h>
export module TNTGraphicButtonAtSpecialCard;
import TEWGraphicButtonWidget;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTGraphicButtonAtSpecialCard : public TEWGraphicButtonWidget
	{
		char unknown37[4];	// 0x0DC
	};
	static_assert(sizeof(TNTGraphicButtonAtSpecialCard) == 0xE0, "TNTGraphicButtonAtSpecialCard size isn't 0xE0.");
	static_assert(sizeof(TNTGraphicButtonAtSpecialCard) <= 0xE0, "TNTGraphicButtonAtSpecialCard size is upper than 0xE0.");
	static_assert(sizeof(TNTGraphicButtonAtSpecialCard) >= 0xE0, "TNTGraphicButtonAtSpecialCard size is lower than 0xE0.");
#pragma pack(pop)
}