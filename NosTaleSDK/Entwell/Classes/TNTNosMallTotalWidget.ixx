module;
#include <stdint.h>
export module TNTNosMallTotalWidget;
import TEWCustomFormWidget;
import String;

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	export struct TNTNosMallTotalWidget : public TEWCustomFormWidget
	{
		char unknown38[8];								// 0x0BC
		uint32_t unknown39;								// 0x0C4
		uint8_t unknown40;								// 0x0C8
		uint8_t unknown41;								// 0x0C9
		uint8_t unknown42;								// 0x0CA
		char unknown43;									// 0x0CB
		struct TNTCuttonEffect* unknown44;				// 0x0CC
		struct TEWControlWidgetEX* unknown45;			// 0x0D0
		TEWControlWidgetEX* unknown46;					// 0x0D4
		struct TEWGraphicButtonWidget* unknown47;		// 0x0D8
		TEWGraphicButtonWidget* unknown48;				// 0x0DC
		TEWGraphicButtonWidget* unknown49;				// 0x0E0
		TEWGraphicButtonWidget* unknown50;				// 0x0E4
		struct TNTNosMallItemShopWidget* unknown51;		// 0x0E8
		struct TNTNosMallBoughtListWidget* unknown52;	// 0x0EC
		struct TNTNosMallPostWidget* unknown53;			// 0x0F0
		uint8_t unknown54;								// 0x0F4
		char unknown55[3];								// 0x0F5
		Properties::Logical::String* unknown56;			// 0x0F8
		Properties::Logical::String* unknown57;			// 0x0FC
		uint32_t unknown58;								// 0x100
		uint32_t dispatch;								// 0x104
		char unknown59[4];								// 0x108
		uint8_t unknown60;								// 0x10C
		char unknown61[3];								// 0x10D
		Properties::Logical::String* unknown62;			// 0x110
	};
	static_assert(sizeof(TNTNosMallTotalWidget) == 0x114, "TNTNosMallTotalWidget size isn't 0x114.");
	static_assert(sizeof(TNTNosMallTotalWidget) <= 0x114, "TNTNosMallTotalWidget size is upper than 0x114.");
	static_assert(sizeof(TNTNosMallTotalWidget) >= 0x114, "TNTNosMallTotalWidget size is lower than 0x114.");
#pragma pack(pop)
}